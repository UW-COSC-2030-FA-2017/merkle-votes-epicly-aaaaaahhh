//Ryan Parziale
//COSC2030
//12-1-2017
//Declaring functions for binary tree class


#pragma once
#include <string>
#include<iostream>
#include<iomanip>
using namespace std;

class bTREE
{
public:
	struct treeNode{
        string data;
        int time;
		treeNode* left;
		treeNode* right;
		bool leaf; //is true if the node is a leaf
		treeNode* next;
		treeNode* prev;

		treeNode(string str, int stamp)
		{
			data = str;
			time = stamp;
			leaf = true;
			left = NULL;
			right = NULL;
			next = NULL;
			prev = NULL;
		}

		treeNode()
		{
			data = "";
			time = 0;
			leaf = true;
			left = NULL;
			right = NULL;
			next = NULL;
			prev = NULL;
		}
    };

	struct linkedList
	{

	public:
		treeNode* head; //pointer to the head of the list
		treeNode* tail; //pointer to the tail of the list
		treeNode* crnt; //pointer to current node
	


		linkedList()
		{
			head = NULL;
			tail = NULL;
			crnt = NULL;
		}

		~linkedList()
		{
			head = NULL;
			tail = NULL;
			crnt = NULL;
		
		}

		void addRight(string data, int time)
		{
			treeNode* tmp = new treeNode(data, time);
			tmp->right = NULL;
			tmp->left = NULL;
			tmp->next = NULL;
			tmp->prev = head;
			
			head->next = tmp;
			head = tmp;
			crnt->right = tmp;

			if (tail == NULL)
			{
				tail = tmp;
			}
			crnt->leaf = false;
		}

		void addLeft(string data, int time)
		{
			treeNode* tmp = new treeNode(data, time);
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->next = NULL;
			tmp->prev = head;

			head->next = tmp;
			head = tmp;
			crnt->left = tmp;

			if (tail == NULL)
			{
				tail = tmp;
			}
			crnt->leaf = false;
			crnt = crnt->next;
		}
		


		bool isEmpty()
		{
			if (tail == NULL || head == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		treeNode* getHead()
		{
			return head;
		}
		treeNode* getTail()
		{
			return tail;
		}

		void removeBack()
		{
			if (!isEmpty())
			{
				tail = tail->prev;
				if (tail != NULL)
				{
					tail->next = NULL;
				}
				else
				{
					head = NULL;
				}
			}
		}

		void add(treeNode* tmp)
		{
			if (!isEmpty())
			{
				head->next = tmp;
				tmp->prev = head;
				tmp->next = NULL;
				head = tmp;
			}
			else
			{
				head = tmp;
				tail = tmp;
				tmp->next = NULL;
				tmp->prev = NULL;

			}

		}


	};
	
private:
	linkedList tree;
	treeNode* root;
    
public:
    
	bTREE();
    ~bTREE();
    
	bTREE* makeLeft(bTREE* tree)
	{
		bTREE* left = new bTREE();
		if (tree->root != NULL)
		{
			
			left->root = tree->root->left;
		}
		else
		{
			left->root = NULL;
		}

		return left;
	}

	bTREE* makeRight(bTREE* tree)
	{

		bTREE* right = new bTREE();

		if (tree->root != NULL)
		{
			right->root = tree->root->right;
		}
		else
		{
			right->root = NULL;
		}

		return right;
	}

    int dataInserted();
    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string);

	int size(const treeNode* subtree)
	{

		if (subtree == NULL)
		{
			return 0;
		}
		else
		{
			return (size(subtree->left) + size(subtree->right) + 1);
		}
	}

	int leaf(treeNode* node)
	{
		if (node == NULL)
		{
			return 0;
		}
		else if (node->leaf == true)
		{
			return 1;
		}
		else
		{
			return (leaf(node->left) + leaf(node->right));
		}

	}
    
	
	//Used instead of the << function
	void testPrint(treeNode* n, int i=0)
	{
		if (n != NULL)
		{
			if (n->left != NULL)
			{
				testPrint(n->left, i + 4);
			}
			if (n->right != NULL)
			{
				testPrint(n->right, i + 4);
			}
			if (i)
			{
				cout << setw(i) << ' ';
			}
			cout << n->data << "\n";
		}

	}

	treeNode* getRoot()
	{
		return root;
	}

    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
	friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

	
	
    
};


