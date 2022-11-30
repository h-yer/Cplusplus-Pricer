#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

template <typename T>
class BinaryTree
{
    private:
    
        int m_depth;
        std::vector<std::vector<T>> m_tree;

    public:

        // Constructor
        BinaryTree(int depth)
        {
            m_depth = depth;
            m_tree.resize(m_depth + 1); // Initialize the full size of the tree
            for (int i = 0; i < m_tree.size(); i++)
                m_tree[i].resize(i + 1); // Initialize the size of each branch
        }

        // Empty Constructor
        BinaryTree() : m_depth(0){}

        //Destructor

        ~BinaryTree(){}

        // Return the depth of the tree
        int getDepth() { return m_depth; }

        // Set depth of the tree
        void setDepth(int depth)
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

        // Return the length of a specified branch
        long getLengthVec(int index) { return m_tree[index].size(); }

        // Assign a value to a specified node
        void setNode(int index1, int index2, T value) { m_tree[index1][index2] = value; }

        // Retrieve the value of a specified node
        T getNode(int index1, int index2) { return m_tree[index1][index2]; }

        // Display the tree
        void display()
        {
            for (int i = 0; i < m_depth + 1; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (j != i)
                    {
                        std::cout << m_tree[i][j] << "\t";
                    }
                    else
                    {
                        std::cout << m_tree[i][j] << std::endl;
                    }
                }
            }

            std::cout << std::endl;

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
                            value = std::to_string(int(m_tree[i][j])*100).length() + 1;
                        switch (value)
                        {
                        case 1:
                            std::cout << "  " << m_tree[i][j] << "   ";
                            break;

                        case 2:
                            std::cout << "  " << m_tree[i][j] << "  ";
                            break;

                        case 3:
                            std::cout << "  " << m_tree[i][j] << "  ";
                            break;

                        case 4:
                            std::cout << m_tree[i][j] << "  ";
                            break;
                        default:
                                
                            std::cout << "Erreur" << " ";
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
                            value = std::to_string(int(m_tree[i][j])*100).length() + 1;
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
                            std::cout << m_tree[i][j] << "  ";
                            break;
                        default:
                            std::cout << "Erreur" << " ";
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
};

