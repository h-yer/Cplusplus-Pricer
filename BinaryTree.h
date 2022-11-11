#pragma once
#include <vector>

template <class T>
class BinaryTree
{
	public:
		BinaryTree(int);
		BinaryTree();

		void setDepth(int);
		void setNode(int, int, T);
		T getNode(int, int);
		void display();

		int getDepth();
		int getLengthVec(int);

	private:
		int m_depth;
		std::vector<std::vector<T>> m_tree;
};
