//
//  SuffixArray.cpp
//  SuffixArray
//
//  Created by Niranjan and Akshay Joshi on 4/29/15.
//   All rights reserved.
//

#include "SuffixArray.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <algorithm>

using namespace std;


SuffixArray::suffix::suffix(int i, string& str)
{
    index = i;
    suff = new string(str);
}

void SuffixArray::insertElements(vector<string> s)
{
    for (int i = 0; i<(int)s.size(); i++)
    {
        suffix* x = new suffix(i,s[i]);
        elements.push_back(x);
    }
}


void SuffixArray::quickSort()
{
  int p;
  int type = 1;
  p=0;
  int r= elements.size()-1;
  {
    Rquick(p,r,type);
  }

  }

  void SuffixArray::Rquick(int p, int r, int type)
  {
    if(p<r)
    {
      int q;
      q=randPartition(p,r,type);
      Rquick(p,q-1,type);
      Rquick(q+1,r,type);
    //q=q+1-1;
    }

  }


int SuffixArray::randPartition(int p, int r, int type)
{
  int pivotIndex;
  std::default_random_engine kashi;
  std::random_device aj;
  std::uniform_int_distribution<int> rand(p,r);
  kashi.seed(aj());
  pivotIndex=rand(kashi);
  return partition(p,r,type,pivotIndex);
}


int SuffixArray::partition(int p, int r, int type,int pivotIndex)
{
    suffix *pivot;
    suffix *temporary;
    vector<suffix*>::iterator it= elements.begin();
    int j;
    j=r;
    if(type==1)
    {
  //    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
      int i = p - 1;
      j=r;
      temporary=elements[pivotIndex];
      elements[pivotIndex]=elements[r];
      elements[r]=temporary;
      pivot =elements[r];
      for (j = p; j < r; j++)
      {
          if (*it[j]->suff <= *pivot->suff)
          {
              i++;
              temporary=elements[i];
              elements[i]=elements[j];
              elements[j]=temporary;
          }
      }
      temporary=elements[i+1];
      elements[i+1]=elements[r];
      elements[r]=temporary;
      return i + 1;
  }
  return j;
}

vector <int> SuffixArray::LCPp()
{
  string temp1;
  string temp2;
  vector <string> temp;
  vector<int>LCP;
  vector<suffix*>::iterator it= elements.begin();
  int n=0;
  int i=0;
  while(it!=elements.end())
  {
      temp.push_back(*elements[i]->suff);
      n++;
      i++;
      it++;
  }
  int k=0;
  LCP.push_back(k);
  n--;
  while(n!=0)
  {
      temp1= temp[n];
      temp2=temp[n-1];
      std::string::iterator its=temp1.begin();
      std::string::iterator its1=temp2.begin();
      k=0;
      while(its[k]== its1[k])
      {
        k++;
      }
      LCP.push_back(k);
      n--;
  }
  k=0;
  LCP.push_back(k);
  return LCP;
}

void SuffixArray::print()
{
  int out;
  vector<int> LCP=LCPp();
  for ( int i = 0; i<(int)elements.size(); i++)
  {
    cout<<"index: "<<elements[i]->index<<"";
    cout<<"\tstring: "<<*elements[i]->suff<<"\t";
    cout<<"LCP: ";
    out=LCP.back();
    cout<<out<<endl;
    LCP.pop_back();
  }
}
