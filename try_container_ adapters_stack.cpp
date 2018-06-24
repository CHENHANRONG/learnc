//
//  try_container_ adapters_stack.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/24.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

int main ( ) {
    
    stack<string> spoken_languages;  //declare stack
    
    spoken_languages.push ( "French" );
    spoken_languages.push ( "German" );
    spoken_languages.push ( "English" );
    spoken_languages.push ( "Hindi" );
    spoken_languages.push ( "Sanskrit" );
    spoken_languages.push ( "Tamil" );
    
    cout << "\nValues in Stack are ..." << endl;
    while ( ! spoken_languages.empty() ) {
        cout << spoken_languages.top() << endl;
        spoken_languages.pop();
    }
    cout << endl;
    
    
    return 0;
}
