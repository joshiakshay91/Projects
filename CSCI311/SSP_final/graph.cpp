/*

 This is graph.cpp has definations of all decleared functions
 of graph.h
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
#include <map>
#include <algorithm>
#include "graph.h"
using std::ios;
using std::istringstream;
using namespace std;
/*This is constructor for graph*/
Graph::Graph()
{
}
/*This is destructor for graph*/
Graph::~Graph()
{
	//~vertex();
}
/*constructor of class vertex*/
Graph::vertex::vertex()
{
	pi = "NIL";
	key= 100;
}
/*Destructor of class vertex*/
Graph::vertex::~vertex()
{
//	  delete pi;
}
/*Constructor of neighbor class*/
Graph::Neighbor::Neighbor()
{

}
/*constructor Neighbor class*/
Graph::Neighbor::Neighbor(string& x,int wght)
{
	name = x;
	weight = wght;
}
/*destructor of neighbor*/
Graph::Neighbor::~Neighbor()
{
//	  delete name;
}

/*The build SSPTree builds shortest path tree from the source that
  is passed*/
void Graph::buildSSPTree(string& source, string& dest)
{
	string c=dest;    //the destination is stroed in here
	c.clear();            //this was used to avoid werror
	for (map<string , vertex*>::
		iterator itr = vertices.begin(); itr!=vertices.end(); itr++)
	{
		if (((*itr).first == source))		//source 0 d
		{
			(*itr).second->key = 0;		//distance 0 key
			(*itr).second->pi = "NIL";	//prev nil	pi
		}
		else if(((*itr).first != source))
		{
			(*itr).second->key = 100;		//distance 0 key
			(*itr).second->pi = "NIL";	//prev nil	pi
		}
		string send=(*itr).first;
		myQ.insert((send), ((*itr).second->key));
	}             //this for loop is pure initilization of ssptree
	bool flag=myQ.isempty();
	while(!flag)
	{
		string nNode;       //neighbouring nodes
		string u=myQ.extractMin();
		for (map<string,vector<Neighbor*> >::
				iterator i = adjList.begin(); i!=adjList.end(); i++)
		{                             //these for loops are for mapping
			string comp=((*i).first); //the node
			if(comp==u)     //and neighbor for relax
			{
				for (vector<Neighbor*>::
						iterator ii = (*i).second.begin();
						ii != (*i).second.end(); ii++ )
				{
					string na1=(*ii)->name; //key decrese
					int wgt=(*ii)->weight;
					relax(u ,na1 , wgt, source );//call relax
				}
			}
		}
		flag=myQ.isempty();
	}
}

/*Relax function this function is called this function helps
  to reduce the distance */
void Graph::relax(string& u, string& na1 , int wgt, string& source)
{
	for (map<string , vertex*>::
		iterator itr1 = vertices.begin(); itr1!=vertices.end(); itr1++)
	{
		if((na1==(*itr1).first)&&(na1!=(source)))
		{
			if((wgt<=((*itr1).second->key))&&((*itr1).second->pi==("NIL")))
			{
				(*itr1).second->key = (wgt);		//distance 0 key
				(*itr1).second->pi = u;	//prev nil	pi
				myQ.decreaseKey((na1), (wgt));
			}
		}
	}
}

/*
   This function is used to add vertices in the graph
 */
void Graph::addVertex(string& s)
{
	int size=s.size();
	size=(size/2);
	osize=size;
	size++;
	while(size>0)
	{
		string temp = s.substr(0, s.find(' '));
		s.erase(0, s.find(' ') + 1);
		vertex* d = new vertex();
		vertices[temp] = d;
		size--;
	}
}

/*This function is used to make adjecency list of the
  graph*/
void Graph::addEdge(string& from, string& to, int weight)
{
	string noder=from.substr(0, from.find(' '));
	from.erase(0, from.find(' ') + 1);
	to=from;
	Neighbor* b = new Neighbor(to,weight);
	adjList[noder].push_back(b);
	insertionSort(noder);
}

/*This function calls build ssptree if we and gets shortest path
  and provides output in the string format*/
string Graph::getShortestPath(string& from, string& to)
{
	string g;
	g.clear();
	string result;
	if(from!=g){
		buildSSPTree(from, to);
		string loop=to;
		int pWeigh=0;
		string output;
		output.clear();
		while(loop!= from)
		{
			for (map<string , vertex*>::iterator itr2 = vertices.begin();
					itr2!=vertices.end(); itr2++)
			{
				string tc=((*itr2).first);
				if(tc==loop)
				{
					alpha.push_back("->");
					alpha.push_back(((*itr2).second->pi));
					pWeigh=pWeigh+((*itr2).second->key);  //data is stored in
					if( ((*itr2).second->pi) != "NIL")    //vector to print as output
					{
						loop=((*itr2).second->pi);
					}
					else
					{
						while (!alpha.empty())
						{
							alpha.pop_back();
						}
						return"NO PATH";
						break;
					}
				}
			}
		}
		while (!alpha.empty())
		{
			output.append(alpha.back());
			alpha.pop_back();
		}
		output.append(to);
		output.append(" with length ");
		std::stringstream sstm;
		sstm << output << pWeigh; //the weight is appended here
		result = sstm.str();
	}
	return result;
}

/*
   This is sorting function to sort adjecency list lexographically
   this code is used as it is from my programming assignment 2 of
   csci 311 Spring 2015
 */
void Graph::insertionSort(string n)
{
	string noder=n;
	vector<Neighbor* > data = adjList[noder];
	vector<Neighbor*>::iterator it = data.begin() ; //i != x.end(); i ++)//
	int key,number;
	int j;
	Neighbor *temp_data;
	number= data.size();
	for (j=1; j<number; j++)
	{
		key=j;
		temp_data=it[key];
		while (key>0 && (it[key-1]->name)> temp_data->name)
		{
			it[key]=it[key-1];
			key--;
		}
		it[key]=temp_data;
	}
}
