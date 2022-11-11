#include "BlackScholesPricer.h"
#include <cmath>
// Constructor
BlackScholesPricer::BlackScholesPricer(Option* option, double asset_price, double interest_rate, double volatility) : m_option(option), m_asset_price(asset_price), m_interest_rate(interest_rate), m_volatility(volatility) { }

// Destructor
BlackScholesPricer::~BlackScholesPricer() { }

// Return the distribution of a standard normal distribution
double BlackScholesPricer::normalDistrib(double x) { return 0.5 * (1 + std::erf(x / std::sqrt(2))); }

// Returns the estimated price with the Black-Scholes formula
double BlackScholesPricer::operator()()
{
	double d1 = (1 / (m_volatility * std::sqrt(m_option->GetExpiry()))) * (std::log(m_asset_price / m_option->GetStrike()) + m_option->GetExpiry() * (m_interest_rate + 0.5 * m_volatility * m_volatility));
	double d2 = d1 - m_volatility * std::sqrt(m_option->GetExpiry());
	if (m_option->GetOptionType() == OptionType::Call)
		if (m_option->isDigital()) // Formula of Cash-or-nothing digital call option
			return normalDistrib(d2) * std::exp(-m_interest_rate * m_option->GetExpiry());
		else // Formula of call option
			return m_asset_price * normalDistrib(d1) - m_option->GetStrike() * std::exp(-m_interest_rate * m_option->GetExpiry()) * normalDistrib(d2);
	else
		if (m_option->isDigital()) // Formula of Cash-or-nothing digital put option
			return normalDistrib(-d2) * std::exp(-m_interest_rate * m_option->GetExpiry());
		else // Formula of put option
			return -m_asset_price * normalDistrib(-d1) + m_option->GetStrike() * std::exp(-m_interest_rate * m_option->GetExpiry()) * normalDistrib(-d2);
}

// Returns the delta of the option
double BlackScholesPricer::delta()
{
	double d1 = (1 / std::sqrt(m_option->GetExpiry())) * (std::log(m_asset_price / m_option->GetStrike()) + m_option->GetExpiry() * (m_interest_rate + 0.5));
	double d2 = d1 - std::sqrt(m_option->GetExpiry());

	if (m_option->GetOptionType() == OptionType::Call)
		if (m_option->isDigital()) // Delta of digital call
			return normalDistrib(d2) * std::exp(-m_interest_rate * m_option->GetExpiry());
		else // Delta of call
			return normalDistrib(d1);
	else
		if (m_option->isDigital()) // Delta of digital put
			return normalDistrib(-d2) * std::exp(-m_interest_rate * m_option->GetExpiry());
		else // Delta of put
			return -normalDistrib(-d1);
}
