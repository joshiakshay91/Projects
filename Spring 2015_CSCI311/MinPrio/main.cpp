/*
The main is driver it calls the functions in MinPriority.cpp
Author:Akshay Joshi
Date 4/27/2015
*/
#include <string>
#include "MinPriority.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
MinPriority myque(-1);

int main()
{
  while(!cin.eof())
  {
    string in;
	  getline (cin, in);
	  string command = in.substr(0, in.find(' '));
	  in.erase(0, in.find(' ') + 1);
    string id =in.substr(0,in.find(' '));
    in.erase(0,in.find (' ')+1);
    int key1;
    istringstream(in)>>key1;
	   if (command == "a") myque.insert (id, key1);
     else if(command =="d") myque.decreaseKey(id, key1);
     else if (command=="x")
     {
       string s=myque.extractMin();
       cout<<s<<endl;
     }
     else if(command=="q") {return 0;}
   }
  return 0;
}
