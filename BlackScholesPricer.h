#pragma once
#include "Option.h"

class BlackScholesPricer
{
	public:
		BlackScholesPricer(Option*, double, double, double);
		~BlackScholesPricer();

		double normalDistrib(double);
		double operator()();
		double delta();

	private:
		Option* m_option;
		double m_asset_price;
		double m_interest_rate;
		double m_volatility;
};