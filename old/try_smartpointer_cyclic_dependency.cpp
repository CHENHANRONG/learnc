//
//  try_smartpointer_cyclic_dependency.cpp
//  learnc
//
// shared_ptr fails to clean up the memory when there is a circular dependency in the application design. Either the application design must be refactored to avoid cyclic dependency, or we can make use of weak_ptr to resolve the cyclic dependency issue.
//Consider there are three classes: A, B, and C. Class A and B have an instance of C, while C has an instance of A and B. There is a design issue here. A depends on C and C depends on A too. Similarly, B depends on C and C depends on B as well.

//  Created by hanrong chen on 6/29/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
using namespace std;

class C;

/* A has member shared pointer C */
class A {
private:
    shared_ptr<C> ptr;
public:
    A() {
        cout << "\nA constructor" << endl;
    }
    
    ~A() {
        cout << "\nA destructor" << endl;
    }
    
    void setObject ( shared_ptr<C> ptr ) {
        this->ptr = ptr;
    }
};


/* B has member shared pointer C */
class B {
private:
    shared_ptr<C> ptr;
public:
    B() {
        cout << "\nB constructor" << endl;
    }
    
    ~B() {
        cout << "\nB destructor" << endl;
    }
    
    void setObject ( shared_ptr<C> ptr ) {
        this->ptr = ptr;
    }
};


/* C constructor contain A and B*/
class C {
private:
    shared_ptr<A> ptr1;
    shared_ptr<B> ptr2;
public:
    C(shared_ptr<A> ptr1, shared_ptr<B> ptr2) {
        cout << "\nC constructor" << endl;
        this->ptr1 = ptr1;
        this->ptr2 = ptr2;
    }
    
    ~C() {
        cout << "\nC destructor" << endl;
    }
};

int main ( ) {
    shared_ptr<A> a( new A() );
    shared_ptr<B> b( new B() );
    shared_ptr<C> c( new C( a, b ) );  // C has A, B
    
    a->setObject ( shared_ptr<C>( c ) );  // A has C
    b->setObject ( shared_ptr<C>( c ) );  //  B has C
    
    return 0;
}
