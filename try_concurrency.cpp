//
//  try_concurrency.cpp
//  learnc
//
//  Created by hanrong chen on 8/22/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <future>
using namespace std;

void sayHello( ) {
    cout << endl << "Hello Concurrency support library!" << endl;
}

int main ( ) {
    future<void> futureObj = async ( launch::async, sayHello );
    futureObj.wait( );
    
    return 0;
}
