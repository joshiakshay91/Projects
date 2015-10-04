/*

This is graph.h this declares all the values for graph.cpp
Author:Akshay Joshi
Date 5/15/2015
Reference:
http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
Introduction To Algorithms, Third Edition
Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest
and Clifford Stein

*/
#include <map>
#include <string>
#include <iostream>
#include "minpriority.h"

class  Graph{

public:

   Graph();
   ~Graph();

private:
  class vertex{
  public:
    string pi;
    int key;
    vertex();
    ~vertex();
  };

  class Neighbor{
  public:
    Neighbor();
    Neighbor(string&, int);
      ~Neighbor();
    public:
      string name;
      int weight;
    };
private:
  string currentSource; //this stores the current source
  map<string, vertex*>  vertices; //has all the info about vertex
  map<string, vector<Neighbor*> > adjList;
  void buildSSPTree(string& source, string& dest);
  void relax(string& u, string& v, int weight, string& source);

public:
  MinPriority myQ;
  void addVertex(string& s);
  void addEdge(string& from, string& to, int weight);
  string getShortestPath(string& from, string& to);
  int osize;    //size of graph that is number of vertices in graph
  void insertionSort(string n); //insertion sort function to sort
  //the vector that is used, this code is used as it is from
  // programming assignment 2 of csci 311
  vector<string> alpha; //vertexes in alphabetical order
};
