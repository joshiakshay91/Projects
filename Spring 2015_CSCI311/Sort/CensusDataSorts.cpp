/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 *
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @edited by- Akshay Joshi
 * @date 3/06/15
 * Refered from:http://www.sanfoundry.com/c-program-implement-quick-sort-using-randomization/
 *              http://www.cplusplus.com/
 *              book: Fundamentals of Computer Algorithms- Ellis Horwitx, Sartaj Sahni, Sanguthevar Rajasekran
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"
#include <stdlib.h>
#include <random>
using std::cout;
using std::string;
//using namespace std;

// formal parameter name commented out to avoid unused variable warning
void CensusData::insertionSort(int type)
{

  vector<Record*>::iterator it= data.begin();
  int key,number;
  int j;
  Record *temp_data;
  number= data.size();
  if(type==0)
    {
      for (j=1; j<number; j++)
         {
           key=j;
           temp_data=it[key];
           while (key>0 && (it[key-1]->population)> temp_data->population)
           {
             it[key]=it[key-1];
             key--;
           }
           it[key]=temp_data;
         }
      }
  else
    {
      for (j=1; j<number; j++)
        {
          key=j;
          temp_data=it[key];
          while (key>0 && (*it[key-1]->city)> *temp_data->city)
          {
            it[key]=it[key-1];
            key--;
          }
          it[key]=temp_data;
        }
    }
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::mergeSort(int type)
{
    int p;
    p=1;
  //  p=p;
    int r= data.size();
    int inf_variable=r;
    inf_variable= inf_variable+2;
    const int inf=inf_variable;
    inf_variable=inf;
  if(type==0)
  {
    AmergeSort(p, r, type);
//    cout<<p<<r<<inf<<"\nafter calling func"<<endl;
  }
  if(type==1)
  {
    AmergeSort(p, r, type);
  }

}

void CensusData::AmergeSort(int p,int r, int type)
{
  int q, q2;
//  cout<<p<<","<<r<<"with inf:"<<inf<<"in merge sort here: values reached"<<endl;
  if (p<r)
  {
    q=(p+r)/2;
    q2=q+1;
    AmergeSort(p,q,type);
    AmergeSort(q2,r,type);
    merge(p, q, r, type);
  }
}

void CensusData::merge(int p, int q, int r, int type)
{
//  cout<<p<<q<<r<<inf<<"in merge here: values reached"<<endl;
  int n1,i,n2,j;
  n1=q-p+1;
  //R=L=1;
  n2=r-q;
  vector<Record*>::iterator it= data.begin();
  vector<int> left;
  vector<string> left_city;
  vector<string> left_state;
  vector<int> right;
  vector<string> right_city;
  vector<string> right_state;
  for(i=0;i<n1;i++)
  {
    left.push_back(it[p+i-1]->population);
    left_city.push_back(*it[p+i-1]->city);
    left_state.push_back(*it[p+i-1]->state);
  }
  for(j=0;j<n2;j++)
  {
    right.push_back(it[q+j]->population);
    right_city.push_back(*it[q+j]->city);
    right_state.push_back(*it[q+j]->state);
  }
  int infi=1999999999;
  left.push_back(infi);
  left_city.push_back("Zzzzzytkavicytaumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu");
  left_state.push_back("Zzzzzytkavicytaumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu");
  right.push_back(infi);
  right_city.push_back("Zzzzzytkavicytaumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu");
  right_state.push_back("Zzzzzytkavicytaumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu");
  if (type==0)
  {
    i=0;
    j=0;
  for(int k=(p-1);k<r;k++)
    {
      if(left[i]<=right[j])
      {
        //cout<<"\n somewhere here::::::";
        (it[k]->population)=left[i];
        (*it[k]->city)=left_city[i];
        (*it[k]->state)=left_state[i];
        i=i+1;
      }
      else
      {
        (it[k]->population)=right[j];
        (*it[k]->city)=right_city[j];
        (*it[k]->state)=right_state[j];
        j=j+1;
      }
    }
  }
  if (type==1)
  {
    i=0;
    j=0;
    for(int k=(p-1);k<r;k++)
    {
      if(left_city[i]<=right_city[j])
      {
        //cout<<"\n somewhere here::::::";
        (it[k]->population)=left[i];
        (*it[k]->city)=left_city[i];
        (*it[k]->state)=left_state[i];
        i=i+1;
      }
      else
      {
        (it[k]->population)=right[j];
        (*it[k]->city)=right_city[j];
        (*it[k]->state)=right_state[j];
        j=j+1;
      }
    }
  }
}

// formal parameter name commented out to avoid unused variable warning
void CensusData::quickSort(int type)
{
  int p;
  p=0;
  int r= data.size()-1;
  //cout<<"r:while leaving:"<<r<<endl;
  //int inf_variable=r;
  //inf_variable= inf_variable+2;
  //const int inf=inf_variable;
  //inf_variable=inf;
  if(type==0)
  {
    Rquick(p,r,type);
  }
  if(type==1)
  {
    Rquick(p,r,type);
  }
}

void CensusData::Rquick(int p, int r, int type)
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
int CensusData::randPartition(int p, int r, int type)
{
int pivotIndex;
std::default_random_engine kashi;
std::random_device aj;
std::uniform_int_distribution<int> rand(p,r);
kashi.seed(aj());
pivotIndex=rand(kashi);
//= p + rand()%(r - p + 1); //generates a random number as a pivot
  return partition(p,r,type,pivotIndex);
}
int CensusData::partition(int p, int r, int type,int pivotIndex)
{
  Record *pivot;
  Record *temporary;
  vector<Record*>::iterator it= data.begin();
  int j;
  j=r;
  if(type==0)
  {
    int i = p - 1;
    //j=r;
    temporary=data[pivotIndex];
    data[pivotIndex]=data[r];
    data[r]=temporary;
    pivot =data[r];
    for (j = p; j < r; j++)
    {

          if(data[j]->population <= pivot->population)
          {
            i++;
            temporary=data[i];
            data[i]=data[j];
            data[j]=temporary;
          }

    }
    temporary=data[i+1];
    data[i+1]=data[r];
    data[r]=temporary;
    return i + 1;
  }
  if(type==1)
  {
//    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int i = p - 1;
    j=r;
    temporary=data[pivotIndex];
    data[pivotIndex]=data[r];
    data[r]=temporary;
    pivot =data[r];
    for (j = p; j < r; j++)
    {
        if (*it[j]->city <= *pivot->city)
        {
            i++;
            temporary=data[i];
            data[i]=data[j];
            data[j]=temporary;
        }
    }
    temporary=data[i+1];
    data[i+1]=data[r];
    data[r]=temporary;
    return i + 1;
}
return j;
}
