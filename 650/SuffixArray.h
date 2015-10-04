//
//  SuffixArray.h
//  SuffixArray
//
//  Created by Niranjan & Akshay Joshi on 4/29/15.
//   All rights reserved.
//

#ifndef __SuffixArray__SuffixArray__
#define __SuffixArray__SuffixArray__

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class SuffixArray
{
private:
    class suffix
    {
    public:
        int index;
        string* suff;

        suffix(int , string&);
    };

public:

    vector<suffix*> elements;

    void insertElements(vector<string>);
    void print();
    void quickSort();
    void Rquick(int, int, int);
    int randPartition(int, int, int);
    int partition(int, int, int,int);
    vector <int> LCPp();

};

#endif /* defined(__SuffixArray__SuffixArray__) */
