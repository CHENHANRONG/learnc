

//
//  try_container_array.cpp
//  learnc
//
//  Created by hanrong chen on 6/20/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<array>

using namespace std;

int main()
{
    array<int,5> a = {1,4,2,5,3};  // array init
    cout<<"\nSize of array is "<<a.size()<<endl;  //array size
    auto pos = a.begin();  //begin iterator
    while(pos != a.end()). //end iterator
    {
        cout<<*pos++<<"\t";
    }
    cout<<endl;
    
    return 0;
}
