//
//  main.cpp
//  SuffixArray
//
//  Created by Niranjan and Akshay Joshi on 4/28/15.
//
//  All rights reserved.
//

#include <iostream>
//#include <ifstream>
#include <vector>
#include <algorithm>
#include <string>
#include "SuffixArray.h"
using namespace std;

int main()
{

  SuffixArray sa;
char test[] = "abaababaabaababaababa$";
vector<string> s;
s.push_back(test);
for (int i = 0; i<21; i++)
{
    std::rotate( test, test+1, test+sizeof(test)-1 ) ;
    //cout<<test<<endl;

    s.push_back(test);
}

sa.insertElements(s);
//sa.print();
sa.quickSort();
sa.print();

}
