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
    /* nitializes the array with five elements.
     array<int,5> a = { 1, 5, 2, 4, 3 };
     The size mentioned can't be changed once declared, just like a C/C++ built-in array.
     The array::size() method returns the size of the array,
     irrespective of how many integers are initialized in the initializer list.
     The auto pos = a.begin() method declares an iterator of array<int,5>
     and assigns the starting position of the array. The array::end() method points to one position after the last element in the array. The iterator behaves like or mimics a C++ pointer, and dereferencing the iterator returns the value pointed by the iterator. The iterator position can be moved forward and backwards with ++pos and --pos, respectively. */
    array<int,5> a = {1,4,2,5,3};   // init array
    for(int index = 0; index<a.size(); ++index){
        a.at(index) = (index+1) * 100;  //random access;
    }
    cout<<"\nSize of array is "<<a.size()<<endl;  //array size
    auto pos = a.begin();  //begin iterator
    while(pos != a.end())  //end iterator
    {
        cout<<*pos++<<"\t";
    }
    cout<<endl;
    
    auto rpos = a.rbegin();  // reverse begin -- last element
    while(rpos != a.rend())  // reverse end -- first element
    {
        cout << *rpos++ << "\t";
    }
    cout << endl;
    
    
    return 0;
}
