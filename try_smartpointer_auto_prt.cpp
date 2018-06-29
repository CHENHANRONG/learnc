//
//  try_smartpointer_auto_prt.cpp
//  learnc
//
//  Created by hanrong chen on 6/28/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

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
        if(&objectBeingAssigned == this)
            return *this;
        
        this->name = objectBeingAssigned.name;
        return *this;
    }
    
    void sayHello( ) {
        cout << "Hello from MyClass " << name << endl;
    }
};

int MyClass::count = 0;

int main ( ) {
    
    auto_ptr<MyClass> ptr1( new MyClass() );  //std::auto_ptr will be deprecated in favor of std::unique_ptr. The choice of smart pointer will depend on your use case and your requirements, with std::unique_ptr with move semantics for single ownership that can be used inside containers (using move semantics) and std::shared_ptr when ownership is shared.You should try to use the smart pointer that best fits the situation, choosing the correct pointer type provides other programmers with insight into your design.
    auto_ptr<MyClass> ptr2( new MyClass() );
    
    ptr1->sayHello();
    ptr2->sayHello();
    
    //At this point the below stuffs happen
    //1. ptr2 smart pointer has given up ownership of MyClass Object 2
    //2. MyClass Object 2 will be destructed as ptr2 has given up its
    //   ownership on Object 2
    //3. Ownership of Object 1 will be transferred to ptr2
    ptr2 = ptr1;
    
    //The line below if uncommented will result in core dump as ptr1
    //has given up its ownership on Object 1 and the ownership of
    //Object 1 is transferred to ptr2.
    // ptr1->sayHello();
    
    ptr2->sayHello();
    
    return 0;
    
}
