#include "BlackScholesMCPricer.h"
#include "MT.h"

// Constructor
BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
	: m_option(option), m_initial_price(initial_price), m_interest_rate(interest_rate), m_volatility(volatility), m_current_estimate(-1), m_nb_paths(0) { }

// Destructor
BlackScholesMCPricer::~BlackScholesMCPricer() { }

// Returns the total number of paths generated
int BlackScholesMCPricer::getNbPaths()
{
	if (m_nb_paths != 0)
		return m_nb_paths;
	else
		throw std::invalid_argument("Error : No path has yet been generated.");
}

// Returns the current estimate of the option price
double BlackScholesMCPricer::operator()()
{
	if (m_current_estimate == -1)
		throw std::invalid_argument("Error : No current estimate has yet been defined.");
	else
		return m_current_estimate;
}

// Generates nb_paths number of paths
void BlackScholesMCPricer::generate(int nb_paths) {
	// This method doesn't work, so we will create a new mt generator
	/*MT& instance = MT::getInstance();
	std::mt19937 generator = instance.getGen();
	double normal = MT::rand_norm(generator);*/

	std::random_device rd;
	std::mt19937 generator(rd());
	double normal = MT::rand_norm(generator);

	double s_next, s_prev;
	double m = 0;

	if (m_option->isAsianOption()) // Number of steps for asian options
		m = m_option->getTimeSteps().size();
	else // Number of steps for european options
		m = 1;

	double expiry = m_option->GetExpiry();
	double step = expiry / m;

	for (int i = 0; i < nb_paths; i++)
	{
		std::vector<double> spot_prices(m + 1); // Initialize new vector h(S0, ..., Sm)
		s_next = 0;	s_prev = m_initial_price; // Initialize S0 and S1
		spot_prices.at(0) = s_prev; // Initialize price at t = 0

		for (int j = 1; j <= m; j++)	// Computing all spot prices for the current path
		{
			s_next = s_prev * std::exp(((m_interest_rate - ((m_volatility * m_volatility) / 2)) * step) + (m_volatility * std::sqrt(step) * normal));
			spot_prices.at(j) = s_next;
			s_prev = s_next;
		}

		// Computing the final price of the current path
		m_current_estimate = (m_nb_paths * m_current_estimate + m_option->payoffPath(spot_prices)) / (m_nb_paths + 1);
		m_nb_paths++;
	}
}

// Returns the confidence interval of the current price
std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	std::vector<double> interval{m_current_estimate - ((2 * m_volatility) / (std::sqrt(m_nb_paths))), m_current_estimate + ((2 * m_volatility) / (std::sqrt(m_nb_paths))) };
	return interval;
}