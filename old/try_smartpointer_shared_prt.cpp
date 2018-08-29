//
//  try_smartpointer_shared_prt.cpp
//  learnc
//
//  Created by hanrong chen on 6/29/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

class MyClass {
private:
    static int count;
    string name;
public:
    MyClass() {
        ostringstream stringStream(ostringstream::ate);
        stringStream << "Object";
        stringStream << ++count;
        
        name = stringStream.str();
        
        cout << "\nMyClass Default constructor - " << name << endl;
    }
    
    ~MyClass() {
        cout << "\nMyClass destructor - " << name << endl;
    }
    
    MyClass ( const MyClass &objectBeingCopied ) {
        cout << "\nMyClass copy constructor" << endl;
    }
    
    MyClass& operator = ( const MyClass &objectBeingAssigned ) {
        cout << "\nMyClass assignment operator" << endl;
        this->name = objectBeingAssigned.name;
        return *this;
    }
    
    void sayHello() {
        cout << "Hello from MyClass " << name << endl;
    }
    
};

int MyClass::count = 0;

int main ( ) {
    
    shared_ptr<MyClass> ptr1( new MyClass() );
    ptr1->sayHello();
    cout << "\nUse count is " << ptr1.use_count() << endl;
    /* In the following code, the scope of the smart pointer ptr2 is wrapped within the block enclosed by flower brackets. Hence, ptr2 will get destroyed at the end of the following code block. The expected use_count function within the code block is 2 */
    {
        shared_ptr<MyClass> ptr2( ptr1 );  //ptr2 share the ptr1 object
        ptr2->sayHello();
        cout << "\nUse count is " << ptr2.use_count() << endl;
    }
    cout << "\nNumber of smart pointers referring to MyClass object after ptr2 is destroyed is "<< ptr1.use_count() << endl;
    
    shared_ptr<MyClass> ptr3 = ptr1;  //ptr3 point to same object as ptr1
    ptr3->sayHello();
    cout << "\nUse count is " << ptr3.use_count() << endl;  // should be 2
    
    return 0;
}
