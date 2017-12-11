//Ryan Parziale
//COSC2030
//12-1-2017
//Defining functions for merkle tree class

#include "pMT.h"
#include<string>
#include<iostream>
using namespace std;

pMT::pMT(int hashSelect)

 // @brief 
 //@param hashSelect a number corresponding to the hashfunction to use for this pMT
 //@return  
{
	selectedHash = hashSelect;
	myMerkle = bTREE();
}

pMT::~pMT()

  //@brief destructor
 // @return nada
 
{
	//pretty sure I dont have to do anything for this so ayyy bitches
	//IM PROBABLY NOT THINKING OF SOMETHING, HUH
}



int pMT::insert(string vote, int time)

// @brief insert a vote and time into a leaf node of tree
// @param vote - a string
// @param time - an int representing the time 
// @return the number of operations needed to do the insert, -1 if out of memory
{
	//no hasing here. hasing done with testhasher function
return myMerkle.insert(vote, time);

}

//int pMT::find(string vote, int time, int hashSelect)
int pMT::find(string vote)
// @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
// @param vote, a string
// @param time, an int
// @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
// @return 0 if not found, else number of opperations required to find the matching vote
{
	string hashed;
	if (selectedHash == 1)
	{
		hashed = hash_1(vote);
	}
	if (selectedHash == 2)
	{
		hashed = hash_2(vote);
	}
	else
	{
		hashed = hash_3(vote);
	}

	return myMerkle.find(hashed);
}


//Left blank because I think this is suppsoed to do the exact same thing as the find function
int pMT::findHash(string mhash)

// @brief does this hash exist in the tree?
// @param mhash, a string to search for in the tree
// @return 0 if not found, else number of opperations required to find the matching hash
{
	//How is this differnt than find???
	return 0;
}


string pMT::locate(string vote)
//Assuming that having this called locateData instead of just locate was a mistake and changed it
 // @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 // @param vote, the data to search for 
 // @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
{
	string hashed;
	if (selectedHash == 1)
	{
		hashed = hash_1(vote);
	}
	if (selectedHash == 2)
	{
		hashed = hash_2(vote);
	}
	else
	{
		hashed = hash_3(vote);
	}
	return myMerkle.locate(hashed);
}



string pMT::hash_1(string key)

// @brief A function that takes in a key and returns a hash of that key using some custom function
// @param key, a string
 // @return a hash of the key

{
	//Badly hashes by turning the word backwards and then padding it to 32 digits
	char tmp;

	int n = key.length();
	for (int i = 0; i < n / 2; i++)
	{
		//swap i and n-i-1
		tmp = key[i];
		key[i] = key[n - i - 1];
		key[n - i - 1] = tmp;

	}
	
	while (key.length() < 32)
	{
		key.insert(0, "0");
	}
	key.resize(32);
	
return key;
}

string pMT::hash_2(string key)
//References the BKDR hash function from Brian Kernighan and Dennis Ritchie's book "The C Programming Language"
//Adjusted the seed value
 // @brief A function that takes in a key and returns a hash of that key using some custom function
 //@param key, a string
 //@return a hash of the key
{
	//multiplies the hash by a seed number then adds to that the value of each character in the key. is divided by 10000 just because they were big numbers.
	//Padded/shortened to 32 characters
	int seed = 232;
	int hash = 0;
	//const char* c = key.c_str();
	for (int i = 0; i < key.length(); ++i)
	{
	
		hash = ((hash*seed) + key[i]);
	}

	string str = to_string(hash);

	while (str.length() < 32)
	{
		str.insert(0, "0");
	}
	str.resize(32);

	return str;
}

string pMT::hash_3(string key)

 // @brief A function that takes in a key and returns a hash of that key using some custom function
 //@param key, a string
 //@return a hash of the key
{

	//Sum of each value of each character in the word but multiplied by 32 raised to a power.
	//The power is the position the character is in the word so that words with the same letters in a different order don't collide
	//Divided by 10000 just because I thought it'd come out to a big number.
	long hash = 0;
	int n = key.length();
	for (int i = 0; i < n; i++)
	{
		hash = (hash + pow(32.0, i)*key[i]);
	}

	string str = to_string(hash);


	while (str.length() < 32)
	{
		str.insert(0, "0");
	}
	str.resize(32);

	return str;
}



string pMT::hashSelect(string data, int i)
{
	if (i == 1)
	{
		return hash_1(data);
	}
	else if (i == 2)
	{
		return hash_2(data);
	}
	else
	{
		return hash_3(data);
	}




}




//friend bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
bool operator ==(const pMT& lhs, const pMT& rhs)
 // @brief Comparison between two merkle trees
 //@param lhs, the left hand side of the equality statment
 // @param rhs, the right hand side of the equality statement
 //@return true if equal, false otherwise
{
	return (lhs.myMerkle == rhs.myMerkle);

}

//friend bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
bool operator !=(const pMT& lhs, const pMT& rhs)
 // @brief Comparison between two merkle trees
 //@param lhs, the left hand side of the equality statment
 //@param rhs, the right hand side of the equality statement
 //@return true if not equal, false otherwise
{
	return (lhs.myMerkle != rhs.myMerkle);
}




//So i DON'T have to do this becauyse this is XOR or??
//friend pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
pMT operator ^(const pMT& lhs, const pMT& rhs)
 // @brief Where do two trees differ
 //@param lhs
 //@param rhs
 //@return a tree comprised of the right hand side tree nodes that are different from the left
{
	return lhs;
}

