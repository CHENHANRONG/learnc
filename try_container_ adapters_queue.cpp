//
//  try_container_ adapters_queue.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/24.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include <iostream>
#include <queue>  //queue
#include <iterator>
#include <algorithm>
using namespace std;

int main () {
    queue<int> q;  //declare queue, FIFO
    
    q.push ( 100 );  //push new value to the end of the queue
    q.push ( 200 );
    q.push ( 300 );
    
    cout << "\nValues in Queue are ..." << endl;
    while ( ! q.empty() ) {  //determine if the queue is empty
        cout << q.front() << endl;  //returns the value in the front of the queue
        q.pop();   // removes the value at the front of the queue
    }
    
    return 0;
}
