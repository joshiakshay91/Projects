//SSPapp.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//#include <ifstream>
#include <fstream>
#include <sstream>
#include <vector>
#include "SSPapp.h"
using std::ios;
using std::istringstream;
using std::ifstream;
using std::string;
using std::vector;
using std::string;


using namespace std;


int main() {
	SSPapp mySSPapp;
	mySSPapp.mainLoop();
	return 0;
}

void SSPapp::mainLoop()
{
  readGraph();
	//while (!cin.eof())
  {
    processQuries();
  }
}

SSPapp::SSPapp(){
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
  //cout<<"vertices are: "<<vertices<<endl;
  cin>>edg;
//	cout<<edg<<"here is num of edges"<<endl;
  c_edges=edg;
  //cout<<"here input this many edges:"<<edg<<endl<<"\n";
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
