/** This file is used to call RB tree and functions of RBT
*This is RBapp file this file calls the function in rbtree.cpp file
* These functions are inserting a node, deleting, finding
*
*
*
* @author Akshay Joshi
* @date 04/13/2015
*/

#include "rbtree.h"
#include "rbapp.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

RBapp::RBapp()
{
	done=false;
}

int main() {
	RBapp myRBTapp;
	myRBTapp.mainLoop();
	return 0;
}

void RBapp::mainLoop()  {
	while (!cin.eof() && !done)
		processCommand();
}

void RBapp::processCommand()
{
	string in;
	getline (cin, in);
	string command = in.substr(0, in.find(' '));
	in.erase(0, in.find(' ') + 1);

	if (command == "insert") processInsert(in);
	else if (command == "print") processPrint();
	else if (command == "find") processFind(in);
	else if (command == "delete") processDelete(in);
	else if (command == "quit") processQuit();
}

void RBapp::processInsert(string& data)
{
	string key = data.substr(0, data.find(' '));
	data.erase(0, data.find(' ') + 1);	//inserts node
	myRBT.rbInsert(key, data);
}

void RBapp::processPrint()
{
	myRBT.rbPrintTree(); 	// prints nodes
}

void RBapp::processFind(string& data)
{
	string key = data.substr(0, data.find(' '));
	vector <const string*> finder =myRBT.rbFind(key);
	vector <const string*>::iterator it;
	it=finder.begin();
	while(it < finder.end())				// finds and prints
	{
		cout <<  key <<' '<< **it;
		it++;
		cout << "\n";
	}
}

void  RBapp::processDelete(string& data)
{
	string key = data.substr(0, data.find(' '));
	data.erase(0, data.find(' ') + 1);			// delete node with with key and sat data
	myRBT.rbDelete(key, data);
}

void  RBapp::processQuit()
{
	if (done==false)
	{
		done =true;								// Quits the program
	}
}
