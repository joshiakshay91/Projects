/*
This is MinPriority.h it has declarations for MinPriority.cpp
Author:Akshay Joshi
Date 4/27/2015
*/
#include <stdio.h>
#include <string>
#include<vector>

using namespace std;
class MinPriority {

private:
  class Element
  {

  public:
     Element(string& ,int);
      string *id;
      int key;
  };

  vector<Element*> minHeap;
  int size;
  void buildMinHeap();
  void minHeapify(int);
  int parent(int);
  int left(int);
  int right(int);

public:

   MinPriority(int size);
  ~ MinPriority();
    void insert(string& , int);
    void decreaseKey(string&, int );
    string extractMin();
    bool isMember(string&);

};
