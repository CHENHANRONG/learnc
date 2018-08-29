//
//  try_functors.cpp
//  learnc
//
//  Created by hanrong chen on 6/20/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T>
class Printer
{
public:
    void operator()(const T& element)
    {
        cout<<element<<"t";
    }
};

int main()
{
    vector<int> v={10,20, 30};
    cout<<"nPrint the vector entries using Functor"<<endl;
    for_each(v.begin(), v.end(),Printer<int>());
    cout<<endl;
    return 0;
}
