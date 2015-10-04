/*
This is MinPriority.cpp it is a queue whih returns minimum value key element
when extract fuction is called.
Author:Akshay Joshi
Date 4/27/2015
*/
#include <string>
#include<iostream>
#include "MinPriority.h"
using namespace std;

MinPriority::MinPriority()
{
  //size=s;
}

MinPriority:: ~MinPriority()
{

}
/*The element values are assigned here*/
MinPriority::Element::Element(string& i, int k)
{
  id =new string(i) ;
  key = k;
}
/*This function inserts the elements in MinPriority*/
void MinPriority::insert(string& id, int key)
{
  Element* x = new Element(id,key);
  minHeap.push_back(x);
  size++;
}

/*This assign new key only if the value is less than current key*/
void MinPriority::decreaseKey(string& id, int newKey)
{
  vector<Element*>::iterator it= minHeap.begin();
  int n;
  int j;
  Element *temp_data;
  int number= minHeap.size();
  for (j=0; j<number; j++)
  {
     n=j;
    temp_data=it[n];
    if((*temp_data->id)==id)
    {
      if(newKey < (temp_data->key))
        {
          temp_data->key=newKey;
        }
      }
    }
}

/*This function extracts the minimum value key and pops out the value from
key*/
string MinPriority::extractMin()
{
  vector<Element*>::iterator it= minHeap.begin();
  Element *temp_data;
  if(!minHeap.empty())
  {
    int n=0;
    int j;
    temp_data=it[n];
    int number= minHeap.size();
    for (j=0; j<number; j++)
    {
      if((temp_data->key)>(it[j]->key))
      {
        temp_data=it[j];
        n=j;
      }
    }
    int m= n;
    minHeap.erase(minHeap.begin()+m);
    string s=*temp_data->id;
    minHeapify(temp_data->key);
    return (s);
  }
  else
  {
    return "empty";
  }
}

bool MinPriority::isMember(string& id)
{
  cout<<id<<endl;
  return false;
}

void MinPriority::buildMinHeap()
{

}

/*This function runs heapify function on the Minpriority queue*/
void MinPriority::minHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  int heap_size=size;
  int bypass=0;
  if(bypass !=0)
  {
    if (l <= heap_size && (l<i))
    {
      smallest = l;
    }
    if (r <= heap_size && (r<i))
    {
      smallest = r;
     }
     if (smallest != i)
     {
       minHeapify(smallest);
     }
  }
}

/*This function returns the value of key's parent*/
int MinPriority::parent(int i)
{
  return (i/2);
}

/*This function will return the left child of the key*/
int MinPriority::left(int i)
{
  return((i*2));
}

/*This function will return the right child of the key*/
int MinPriority::right(int i)
{
  return(((i*2)+1));
}


bool MinPriority::isempty()
{
  if(  minHeap.empty())
  {
   return true;
  }
  else
  {
    return false;
  }

}
