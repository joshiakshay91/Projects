//Graph.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Graph.h"
//#include "SSPapp.h"
using std::ios;
using std::istringstream;
using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{

}

Graph::vertex::vertex()
{
  pi = "nil";
  key= 100;
}

Graph::vertex::~vertex()
{
//  delete pi;
}

Graph::Neighbor::Neighbor()
{

}

Graph::Neighbor::Neighbor(string& x,int wght)
{
       name = x;
     weight = wght;
}

Graph::Neighbor::~Neighbor()
{
//  delete name;
}


void Graph::buildSSPTree(string& source, string& dest)
{
//  cout<<"meS: "<<meS<<endl;
//  if(source == meS)
  for (map<string , vertex*>::iterator itr = vertices.begin(); itr!=vertices.end(); itr++)
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
    }
      bool flag=myQ.isempty();
      while(!flag)
      {
        string nNode;       //neighbouring nodes
        string u=myQ.extractMin();
        for (map<string,vector<Neighbor*> >::iterator i = adjList.begin(); i!=adjList.end(); i++)
          {
            string comp=((*i).first);
            if(comp==u)
            {
          //    cout<<"vertex: "<< (*i).first<<": "<<endl;
              for (vector<Neighbor*>::iterator ii = (*i).second.begin(); ii != (*i).second.end(); ii++ )
              {
                  myQ.decreaseKey(((*ii)->name), ((*ii)->weight) );
                  string na1=(*ii)->name;
                  int wgt=(*ii)->weight;
                  relax(u ,na1 , wgt, source );
                }
              }
            }

/*        vector<Neighbor* > x = adjList[u];
        for (vector<Neighbor*>::iterator i = x.begin() ; i != x.end(); i ++)//
        {
          if(((*i)->name)== source)
            {
              cout<<"name is "<<(*i)->name<<endl;
              cout<<"weight "<<(*i)->weight<<endl;
            }
        }*/
        flag=myQ.isempty();
            //int temp;
            //temp=dist u;
        }
}


void Graph::relax(string& u, string& na1 , int wgt, string& source)
{
for (map<string , vertex*>::iterator itr1 = vertices.begin(); itr1!=vertices.end(); itr1++)
  {
    if((na1==(*itr1).first)&&(na1!=(source)))
    {
        if((wgt<=((*itr1).second->key))&&((*itr1).second->pi==("NIL")))
        {
        (*itr1).second->key = (wgt);		//distance 0 key
        (*itr1).second->pi = u;	//prev nil	pi
        }
      }
    }
}
void Graph::addVertex(string& s)
{
  int size=s.size();
  size=(size/2);
  int osize=size;
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

void Graph::addEdge(string& from, string& to, int weight)
{
  string noder=from.substr(0, from.find(' '));
  from.erase(0, from.find(' ') + 1);
  to=from;

  Neighbor* b = new Neighbor(to,weight);
  adjList[noder].push_back(b);
  insertionSort(noder);
//  std::sort (adjList[noder].begin(), adjList[noder].end());
}

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
//  cout<<"TO:"<<to<<endl;
  while(loop!= from)
  {
      for (map<string , vertex*>::iterator itr2 = vertices.begin(); itr2!=vertices.end(); itr2++)
      {
        string tc=((*itr2).first);
        if(tc==loop)
        {
            alpha.push_back("->");
            alpha.push_back(((*itr2).second->pi));
            pWeigh=pWeigh+((*itr2).second->key);
            if( ((*itr2).second->pi) != "NIL")
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
  sstm << output << pWeigh;
  result = sstm.str();
  //cout<<result<<endl;
}
 return result;
}

void Graph::insertionSort(string n)
{
  string noder=n;
//  adjList[noder].push_back(b);
//  std::sort (adjList[noder].begin(), adjList[noder].end());
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
