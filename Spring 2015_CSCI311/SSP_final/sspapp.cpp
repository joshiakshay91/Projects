/*

   This is single shortest path apps .cpp this driverf unction of the
   whole ssp tree.
Author:Akshay Joshi
Date 5/15/2015
Reference:
http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
Introduction To Algorithms, Third Edition
Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest
 and Clifford Stein

 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "sspapp.h"
using std::ios;
using std::istringstream;
using std::ifstream;
using std::string;
using std::vector;
using std::string;


using namespace std;

/*main function*/
int main() {
	SSPapp mySSPapp;
	mySSPapp.mainLoop();
	return 0;
}
/*
   this is loop for reading the graph and processing queries
 */
void SSPapp::mainLoop()
{
	readGraph();
	processQuries();
}
/*app constructor*/
SSPapp::SSPapp()
{

}

SSPapp::Edge::Edge(string& nodes, int we) {
	c = new string(nodes);
	w = we;
}

/*
   destructor.
 */
SSPapp::Edge::~Edge() {
	delete c;
}

/*This function reads graph*/
void SSPapp::readGraph()
{
	int vert;
	int edg,c_edges;//number of edges and its counter
	string vertices;  //string of vertexs
	string input,to;
	to="\0";
	cin>>vert;
	getline(cin >> ws,vertices);
	myGraph.addVertex(vertices);
	cin>>edg;
	c_edges=edg;
	SSPapp::Edge* edge;
	while(c_edges > 0)
	{
		getline (cin >> ws, input);
		string command = input.substr(0, input.rfind(' '));
		input.erase(0, input.rfind(' ') + 1);
		string str=input;
		char * CONV = new char[str.size() + 1];
		copy(str.begin(), str.end(), CONV);
		CONV[str.size()] = '\0';
		int weigh = atoi (CONV);
		edge = new SSPapp::Edge(command, weigh);
		data.push_back(edge);
		myGraph.addEdge(command,to,weigh);
		c_edges--;
	}
}

/*
   This function takes input of queries and passes SSPtree
 */
void SSPapp::processQuries()
{
	string inp;
	string source;
	string dest;
	while((!cin.eof()))
	{
		getline (cin >> ws, inp);
		source = inp.substr(0, inp.find(' '));
		inp.erase(0, inp.find(' ') + 1);
		dest =inp;
		inp.clear();
		string result =	myGraph.getShortestPath(source,dest);
		cout<<result<<endl;
	}
}
