//Ryan Parziale
//COSC2030
//12-1-2017
//Declaring functions for merkle tree class


#pragma once

#include "bTREE.h"
#include<iostream>
#include <string>
using namespace std;
class pMT
{
private:
    int selectedHash;
    bTREE myMerkle;
    
    string hash_1(string);
    string hash_2(string);
    string hash_3(string);
    
public:

    pMT(int);
    ~pMT();
    
    
    int insert(string, int);

	string hashSelect(string data, int i);
    
	int find(string);

   //Doesn't this just do the exact same thing as the find function?
	int findHash(string);
    
    string locate(string);


	bTREE::treeNode* getTheRoot()
	{
		return myMerkle.getRoot();
	}

	void testHasher(bTREE::treeNode* root, int i)
	{
		if (root != NULL)
		{
			testHasher(root->left, i);
			testHasher(root->right, i);

			if (root->left != NULL && root->right != NULL)
			{
				root->data = hashSelect(root->left->data, i) + hashSelect(root->right->data, i);
			}
			else if (root->left != NULL && root->right == NULL)
			{

				root->data = hashSelect(root->left->data, i);
			}
			else if (root->left == NULL && root->right != NULL)
			{

				root->data = hashSelect(root->right->data, i);
			}
			else
			{
				root->data = hashSelect(root->data, i);
			}
		}

	}
    
	//Used instead of the << function to display the tree
	void printingmaybe()
	{
		myMerkle.testPrint(myMerkle.getRoot(), 0);
	}

    friend bool operator==(const pMT& lhs, const pMT& rhs);
    
    friend bool operator!=(const pMT& lhs, const pMT& rhs);
    
    friend pMT operator^(const pMT& lhs, const pMT& rhs);

    
};


