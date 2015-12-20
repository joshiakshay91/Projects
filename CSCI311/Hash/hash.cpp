/*
Author: Akshay Joshi
Description: Different functions like processing input, searching, deleteing, and
adding content are executed from here.
Reference: www.cplusplus.com
*/

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include <string.h>
#include <fstream>
#include"hash.h"
using namespace std;

Hash :: Hash()
{
	collisions =0;
	longestList=0;
	avgLength=0;
}
/*
process file is used to get input commands from file here average length, collisions and
longest list is calculated for input of a string.*/
void Hash::processFile(string key)
{
	int index, temp = 0, temp2 = 0, i=0;		// temp varibales are used for longest lis calculations
	ifstream filein(key.c_str());
	string word;
	if (filein.is_open())
	{
		{
			while(getline(filein, word))
			{
				index = hf(word);																						// hash function is called
				hashTable[index].emplace_back(word);
				avgLength = (avgLength + averagecal()) / 2.0;				// average for successful addition of
			}																																												// string
		}
		 filein.close();
	}
	list < string > ::iterator itr;
	while(i< HASH_TABLE_SIZE)
	{
		collisions=collisions+hashTable[i].size();								// adding the collisions
		temp2=hashTable[i].size();
		if (temp2>=temp)
		{
			temp = temp2;
		}
		i++;
	}
	collisions = collisions - HASH_TABLE_SIZE;		//number of collisons
	longestList = temp;
}

/*This functions is used for searching string it is also called for remove as it returns
boolean value for searching element*/

bool Hash::search(string key)
{
	bool flag=false;														// flag initialization
	list < string > ::iterator i;
	int index;
	index=hf(key);
	i = hashTable[index].begin();
	while(i!=hashTable[index].end())
	{
		if (key == *i)
		{
			flag=true;										//if string is found the string flag is marked true and loop is broken
			break;
		}
		i++;
	}
	return flag;										// returns the flag true or false
}

/*Remove function calls search function if flag returned is true it goes to index where
string is present it removes the string and calls avgLength function*/

void Hash::remove(string key)
{
		if ( search ( key) )
		{
			int index;
			index=hf(key);
			hashTable[index].remove(key);
			avgLength = (avgLength + averagecal()) / 2.0;
		}
}

/*This functions is used to print entire content of table*/

void Hash::print()
{
	list < string > ::iterator itr;
	int size=0;
	while(size<HASH_TABLE_SIZE)
	{
		cout << size <<":\t";
		itr = hashTable[size].begin();
		while(itr!=hashTable[size].end())
		{
			cout << *itr<<", ";							// prints the values
			itr++;
		}
		cout << "\n";
	size++;
	}
}

/*This function gives output to hash.out file the hash table is printed out in this file */

void Hash::output(string)
{
	{
		ofstream fileout;								//do the ofstream commond for creating file
		fileout.open("hash.out");
		{
			list < string > ::iterator itr;			// this for loop is for traversing throug the index
			int size=0;
			while(size<HASH_TABLE_SIZE)
			{
				fileout << size << ":\t";
				itr = hashTable[size].begin();
				while(itr != hashTable[size].end())	// this for loop is for traversing through the link
				{
					fileout << *itr << ", ";
					itr++;
				}
				fileout << endl;							//giving out the output
				size++;
			}
		}
		fileout.close();									// closing the file to which the data is written
	}
}

/*This function is used to get running average of hash table*/

double Hash::averagecal()
{
	double total = 0, avg = 0;
	int itre=0;
	int size=0;
	while(itre<HASH_TABLE_SIZE)
	{
		total =total+ hashTable[itre].size();
		if(!hashTable[itre].empty())
	    {
	      size++;
	    }
		itre++;
	}
	avg = total /(size);
	return avg;
}

/* This function is used to calculate the load*/

double Hash::load()
{
	list < string > ::iterator itr;
	double load;
	int i=0;
	double elements=0, size=0;
	size= HASH_TABLE_SIZE;
	while(i< HASH_TABLE_SIZE)
	{
		itr = hashTable[i].begin();
		while(itr != hashTable[i].end())
		{
			elements++;								// keep on counting the number of elements added on each table
			itr++;
		}
		i++;
	}
	load= (elements/size);	//HASH_TABLE_SIZE);
	return load;
}

/*This function is used to print statistics i.e load, running avg, collisions and longest
list*/

void Hash::printStats()
{
	double loder;
	loder=load();
	cout << "Total Collisions = " << collisions << endl; 	// print the stats
	cout << "Longest List Ever = " << longestList << endl;
	cout << "Average List Length Over Time = "<< avgLength<< endl;
	cout << "Load Factor = "<<  loder << endl;
}
