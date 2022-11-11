#pragma once
#include "Option.h"
#include "BinaryTree.h"

class CRRPricer
{
	public:
		CRRPricer(Option*, int, double, double, double, double);
		CRRPricer(Option*, int, double, double, double);
		~CRRPricer();

		void compute();
		double get(int, int);
		double operator()(bool closed_form = false);
		void display();
		double facto(int);
		bool getExercise(int, int);

	private:
		BinaryTree<double> m_tree;
		BinaryTree<bool> m_exercise;
		Option* m_option;
		double m_up;
		double m_down;
		double m_price;
		double m_interest_rate;
};