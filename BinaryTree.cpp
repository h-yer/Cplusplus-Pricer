
#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree(int depth) : m_depth(depth)
{
	m_tree = std::vector<std::vector<T>>(m_depth + 1); // Initialize the full size of the tree
	for (int i = 0; i < m_tree.size(); i++) 
		m_tree[i].resize(i + 1); // Initialize the size of each branch
}

// Empty Constructor
template <typename T>
BinaryTree<T>::BinaryTree() : m_depth(0), m_tree(std::vector<std::vector<T>>(0)) {}


//Destructor
template<typename T>
BinaryTree<T>::~BinaryTree()
{

}

// Set depth of the tree
template <typename T>
void BinaryTree<T>::setDepth(int depth)
{
	if (m_depth > depth) // If initial depth is greater than input depth, shrink the tree
	{
		m_depth = depth;
		m_tree.resize(m_depth + 1);
	}
	else { // Otherwise, create new branches
		m_tree.resize(depth + 1);
		for (int i = m_depth; i < m_tree.size(); i++)
			m_tree[i].resize(i + 1);
		m_depth = depth;
	}
}

// Assign a value to a specified node
template <typename T>
void BinaryTree<T>::setNode(int index1, int index2, T value) { m_tree[index1][index2] = value; }

// Retrieve the value of a specified node
template <typename T>
T BinaryTree<T>::getNode(int index1, int index2) { return m_tree[index1][index2]; }

// Display the tree
template <typename T>
void BinaryTree<T>::display()
{
	for (int i = 0; i < m_tree.size(); i++)
	{
		int space = m_depth * 3 + 3 - 3 * i;

		if (i == m_tree.size() - 1)
		{
			for (int k = 0; k < space; k++)
			{
				std::cout << " ";
			}

			for (int j = 0; j < m_tree[i].size(); j++)
			{
				long value = 0;
				if (int(m_tree[i][j]) == m_tree[i][j])
					value = std::to_string(int(m_tree[i][j])).length();
				else
					value = std::to_string(round(double(m_tree[i][j]))).length();
				switch (value)
				{
				case 1:
					std::cout << "  " << m_tree[i][j] << "   ";
					break;

				case 2:
					std::cout << "  " << m_tree[i][j] << "  ";
					break;

				case 3:
					std::cout << " " << m_tree[i][j] << "  ";
					break;

				case 4:
					std::cout << m_tree[i][j];
					break;
                default:
                    std::cout << "ERREUR";
				}
			}
			std::cout << std::endl << std::endl;
		}
		else
		{
			for (int k = 0; k < space; k++)
			{
				std::cout << " ";
			}

			for (int j = 0; j < m_tree[i].size(); j++)
			{
				long value = 0;
				if (int(m_tree[i][j]) == m_tree[i][j])
					value = std::to_string(int(m_tree[i][j])).length();
				else
					value = std::to_string(round(float(m_tree[i][j]))).length();
				switch (value)
				{
				case 1:
					std::cout << "  " << m_tree[i][j] << "   ";
					break;

				case 2:
					std::cout << "  " << m_tree[i][j] << "  ";
					break;

				case 3:
					std::cout << " " << m_tree[i][j] << "  ";
					break;
				case 4:
					std::cout << m_tree[i][j];
					break;
				}
			}

			std::cout << std::endl;

			for (int k = 0; k < space; k++)
			{
				std::cout << " ";
			}

			for (int j = 0; j < m_tree[i].size(); j++)
			{
				std::cout << "/   \\ ";
			}

			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

// Return the depth of the tree
template <typename T>
int BinaryTree<T>::getDepth() { return m_depth; }

// Return the length of a specified branch
template <typename T>
int BinaryTree<T>::getLengthVec(int index) { return m_tree[index].size(); }
