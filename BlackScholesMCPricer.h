#pragma once
#include "Option.h"

class BlackScholesMCPricer
{
	public:
		BlackScholesMCPricer(Option*, double, double, double);
		~BlackScholesMCPricer();

		int getNbPaths();
		void generate(int);
		double operator()();
		std::vector<double> confidenceInterval();


	private:
		Option* m_option;
		double m_initial_price;
		double m_interest_rate;
		double m_volatility;
		double m_current_estimate;
		int m_nb_paths;
};

