//
//  try_container_vector.cpp
//  learnc
//
//  Created by hanrong chen on 6/20/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include<vector>
#include<algorithm>


/* Vector is a quite useful sequence container, and it works exactly as an array,
 except that the vector can grow and shrink at runtime while an array is of a fixed size.
 However, the data structure used under the hood in an array
 and vector is a plain simple built-in C/C++ style array.   */


using namespace std;

int main()
{
    vector<int> v={ 1, 5, 2, 4, 3 };  //init vector
    cout<<"\nSize of vector is "<<v.size()<<endl;  // vector size
    auto pos = v.begin();  // get vector begin element iterator
    cout << endl<<"Print vector elements before sorting" << endl;
    while(pos != v.end())  // != operator for iterator and vector end element iterator
    {
        cout << *pos++ << "\t";
    }
    cout<<endl;
    sort( v.begin(), v.end() );  //sort API
    pos = v.begin();
    cout << "\nPrint vector elements after sorting" << endl;
    
    while ( pos != v.end() )
        cout << *pos++ << "\t";
    cout << endl;
    
    return 0;

}
