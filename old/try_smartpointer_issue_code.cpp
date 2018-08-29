//
//  try_smartpointer_issue_code.cpp
//  learnc
//
//  Created by hanrong chen on 6/28/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
using namespace std;

class MyClass {
public:
    void someMethod() {
        
        int *ptr = new int();
        *ptr = 100;
        int result = *ptr / 0;  //division by zero error expected
        delete ptr;  //memory leak, using valgrind --leak-check=full --show-leak-kinds=all ./try_smartpointer_issue_code to check
        cout<<"result="<<result<<endl;
    }
};

int main ( ) {
    
    MyClass objMyClass;
    objMyClass.someMethod();
    
    return 0;
    
}
