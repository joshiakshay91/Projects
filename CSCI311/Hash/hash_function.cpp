/*
Author: Akshay Joshi
This assignment originated at UC Riverside.
*/
#include <string>
#include "hash.h"

using std::string;

int Hash::hf ( string ins )
{
    int hash = 0;
  	int index = 0;
  	int j = 4;
    int val;
  	for (int i = 0; i < j; i++)
  	{
  		hash = hash + (int)ins[i];
  	}
  	val = hash;
  	hash = hash*hash*hash;     // I thought of geometric value of Cube and Circle
    val= val*val*3.14;          //Here I take area of circle; pi is 3 over here
    hash=hash+val;            //added the value of cube volume and area of circle
  	index = hash % HASH_TABLE_SIZE;  //divided by table size to keep in the limits
  	return index;
  // place your hash function here....
  //    return ( (int) ins[0] ) % HASH_TABLE_SIZE;
}
