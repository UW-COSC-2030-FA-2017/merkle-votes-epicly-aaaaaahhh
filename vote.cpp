//Ryan Parziale
//COSC2030
//12-1-2017
//Testing the merkle and binary tree classes



#include <stdio.h>
#include "pMT.h"
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char **argv)
{
	
	//Read in the file once and count how many leaf nodes you'll need then make a tree with that many leaf nodes
	ifstream inFile;
	string str;
	int leafNum = 0;

	//Opening file
	inFile.open("Tab Seperated File.txt");
	if (inFile.is_open())
	{
	cout << "file open" << endl;
	getline(inFile, str);
	getline(inFile, str); //because the first line is not any actual data and needs to be skipped
	while (!inFile.eof())
	{
	leafNum = leafNum + 1;
	getline(inFile, str);
	}
	}

	inFile.close();

	cout << "Number of lead nodes needed: " << leafNum << endl; //41 leaf nodes
	//6 levels of nodes will be needed for this
	//Or, 5 completed levels and then one level for all the added leaf nodes
	//That means 31 blank nodes must be created


	pMT tree1 = pMT(1);

	for (int i = 0; i < 31; i++)
	{
		tree1.insert("", 0); //inserting 31 blank nodes into the merkle tree
	}

	
	//Opening up the file and inserting the actual data
	string data = "";
	int timeStamp = 0;
	inFile.open("Tab Seperated File.txt");
	if (inFile.is_open())
	{
		getline(inFile, str);
		while (!inFile.eof())
		{
			tree1.insert(data, timeStamp);
			inFile >> data;
			inFile >> timeStamp;
		}

	}

	//hashing the tree
	tree1.testHasher(tree1.getTheRoot(),1);

	//Returing the value of the root node
	cout << "Root node of the hashed tree: " << tree1.getTheRoot() << endl;





	//Will now read in and construct the same tree to compare the two and see if they are valid
	pMT tree2 = pMT(1);

	for (int i = 0; i < 31; i++)
	{
		tree2.insert("", 0); //inserting 31 blank nodes into the merkle tree
	}


	//Opening up the file and inserting the actual data
	data = "";
	timeStamp = 0;
	inFile.open("Tab Seperated File.txt");
	if (inFile.is_open())
	{
		getline(inFile, str);
		while (!inFile.eof())
		{
			tree2.insert(data, timeStamp);
			inFile >> data;
			inFile >> timeStamp;
		}

	}

	//hashing the tree
	tree2.testHasher(tree2.getTheRoot(), 1);
	
	//Returing the value of the root node
	cout << "Root node of the second hashed tree: " << tree1.getTheRoot() << endl;




	if (tree1 == tree2)
	{
		cout << "Valid" << endl;
	}
	else
	{
		cout << "Invalid" << endl;
	}


	if (tree1 != tree2)
	{
		cout << "Invalid" << endl;
	}
	else
	{
		cout << "Valid" << endl;
	}

	return 0;
}

