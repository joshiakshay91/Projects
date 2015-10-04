//Graph.h
#include <map>
#include <string>
#include <iostream>
#include "MinPriority.h"

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
//  vector <vertex*> data;                  // getting inputs

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
  //void vertices(string&);//,vertex);
  map<string, vertex*>  vertices;//adj
 map<string, vector<Neighbor*> > adjList;
//  void adjList(string&);//, vector<Neighbor>);
  void buildSSPTree(string& source, string& dest);
  void relax(string& u, string& v, int weight, string& source);

public:
  MinPriority myQ;
  void addVertex(string& s);
  void addEdge(string& from, string& to, int weight);
  string getShortestPath(string& from, string& to);
  int osize;
  // infinity=100;
  void insertionSort(string n);
  vector<string> alpha; //vertexes in alphabetical order
};
