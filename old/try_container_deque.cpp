//
//  try_container_deque.cpp
//  learnc
//
//  Created by hanrong chen on 6/21/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//
#include <iostream>
#include<deque>
#include<iterator>
#include<algorithm>
using namespace std;

/* The deque container is a double-ended queue
 and the data structure used could be a dynamic array or a vector.
 In a deque, it is possible to insert an element both at the front and back,
 with a constant time complexity of O(1), unlike vectors,
 in which the time complexity of inserting an element at the back is O(1)
 while that for inserting an element at the front is O(N).
 The deque doesn't suffer from the problem of reallocation,
 which is suffered by a vector.
 However, all the benefits of a vector are there with deque,
 except that deque is slightly better in terms of performance
 as compared to a vector as there are several rows of dynamic arrays or vectors in each row.
 
 The following diagram shows the internal data structure used in a deque container: */

int main () {
    deque<int> d = { 10, 20, 30, 40, 50 };
    
    cout << "\nInitial size of deque is " << d.size() << endl;
    
    d.push_back( 60 );  //push back
    d.push_front( 5 );  //push from
    
    cout << "\nSize of deque after push back and front is " << d.size() << endl;  //size
    
    copy ( d.begin(), d.end(), ostream_iterator<int>( cout, "\t" ) );  //begin, end
    d.clear();  //clear
    
    cout << "\nSize of deque after clearing all values is " << d.size() <<
    endl;
    
    cout << "\nIs the deque empty after clearing values ? "
    << ( d.empty() ? "true" : "false" ) << endl;  //empty
    
    return 0;
}

