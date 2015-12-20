/*

This is single shortest path apps .h this is driver function's
header,  this has all the declarations for sppapp.cpp
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
#include <iostream>   // std::cout
#include "graph.h"
#include <fstream>
#include <sstream>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
using std::string;

class SSPapp {

public:
        SSPapp();                       // constructor
        void mainLoop();           // process commands until done
        void readGraph();
        void processQuries();

private:
      Graph myGraph;
      class Edge {                      // declaration of edges
   public:
      string* c;                             //for nodes
      int w;                                   //weights
      Edge(string&, int);
      ~Edge();
   };
   vector <Edge*> data;                  // getting inputs

};
