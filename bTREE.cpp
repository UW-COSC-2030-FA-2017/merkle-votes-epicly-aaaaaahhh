//Ryan Parziale
//COSC2030
//12-1-2017
//Defining functions for binary tree class


#include "bTREE.h"
#include<string>
#include<iostream>
using namespace std;

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	linkedList tmp = linkedList();
	tree = tmp;
	root = NULL;
}

bTREE::~bTREE()
{
	tree.head = NULL;
	tree.tail = NULL;
	tree.crnt = NULL;
	root = NULL;
}

int bTREE::dataInserted()
{
	return leaf(root); //return the total number of DATA nodes inserted in the tree. So the number of leaf nodes.
}


int bTREE::numberOfNodes()
{
	return size(root); //return the total number of nodes, leaf nodes or not.
}


//returns the number of operations needed to do the insert, -1 if out of memory
int bTREE::insert(string data, int time)
{
	
	
	if (tree.crnt != NULL)
	{
		if (tree.crnt->right == NULL)
		{
			tree.addRight(data, time);

		}
		else
		{
			tree.addLeft(data, time);
			//Otherwise, the right side of that node already points to something, so you add something to the left side.
			tree.crnt = tree.crnt->next;
		}
	}
	else
	{
		treeNode* tmp = new treeNode(data, time);
		tree.head = tmp;
		tree.tail = tmp;
		tree.crnt = tmp;
		root = tmp;
	}
	return 1; //returns the number of operations needed to do the insert, -1 if out of memory
	//This is always 1, which is just making a new node and inserting it either to the right or the left
}


//returns 0 if the string is not found, otherwise returns the number of opperations required to find the matching vote
int bTREE::find(string str)
{
	linkedList S = linkedList();
	treeNode* current = new treeNode();
	current = tree.tail; //The root
	bool done = 0;
	bool found = 0;

	int operations = 1;

	while (!done)
	{

		if (current != NULL)
		{
			if (current->data == str)
			{
				done = 1;
				found = 1;
			}
			else
			{
				operations = operations + 1;
				S.add(current);
				current = current->left;

			}

		}
		else
		{

			if (!S.isEmpty())
			{
				current = S.getHead();
				S.removeBack();
				operations = operations + 1;
				current = current->right;


			}
			else
			{
				done = 1;
			}
		}

		
		
		//returns 0 if the string is not found, otherwise returns the number of opperations required to find the matching vote

	}

	if (!found)
	{
		return 0;
	}
	else
	{
		return operations;
	}
}



//Path returned is read from right to left
string bTREE::locate(string str)
{
	//return sequence of L's and R's to get from root node to location of string. if not found, return a "."


	linkedList S = linkedList();
	treeNode* current = new treeNode();
	current = tree.tail; //The root
	bool done = 0;
	bool found = 0;
	string path = ""; //the path to the string in the tree if it exists

	while (!done)
	{

		if (current != NULL)
		{
			if (current->data == str)
			{
				done = 1;
				found = 1;
			}
			else
			{
				S.add(current);
				current = current->left;
				path += "L";
			}

		}
		else
		{

			if (!S.isEmpty())
			{
				current = S.getHead();
				S.removeBack();
				path.pop_back();
				current = current->right;
				path += "R";

			}
			else
			{
				done = 1;
			}
		}
	

		
	}

	/*
	create an empty stack, S
	initialize current node as root
	push current node to S and set current to current->left until current is NULL (or the string matches)
	if current is NULL and the stack isnt empty then pop the last item from the stack
	set current to the poppitem->right
	push current node to S and set current to current->left.....
	*/


	if (!found)
	{
		return ".";
	}
	else
	{
		return path;
	}
}



//Note this change in the README file
//friend bool bTREE::operator ==(const bTREE& lhs, const bTREE& rhs)
bool operator==(const bTREE& lhs, const bTREE& rhs)
{
	if (lhs.root->data == rhs.root->data)
	{
		return true;
	}
	else
	{
		return false;
	}

//JUST CHECK THE HASH STORED IN THE ROOT NODE
}

//friend bool bTREE::operator !=(const bTREE& lhs, const bTREE& rhs)
bool operator !=(const bTREE& lhs, const bTREE& rhs)
{
	if (lhs.root->data != rhs.root->data)
	{
		return true;
	}
	else
	{
		return false;
	}
	//Okay, i'm not sure if that's what I'm actually supposed to do with this function
}
