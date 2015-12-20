//sspApp
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>   // std::cout
#include "Graph.h"
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
        void mainLoop();               // process commands until done
        void readGraph();
        void processQuries();

private:
      Graph myGraph;
      class Edge {                         // declaration of edges
   public:
      string* c;          //for nodes
      int w;                //weights
      Edge(string&, int);
      ~Edge();
   };
   vector <Edge*> data;                  // getting inputs

};
