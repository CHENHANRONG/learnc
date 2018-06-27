//
//  try_temlate_programming_class_template_dynamic_array.cpp
//  learnc
//
//  Created by hanrong chen on 6/27/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

/* however, there is a performance issue with the DynamicArray design approach.
 For bool value: while true can be represented by 1 and false can be represented by 0,
 which requires just 1 bit, the below DynamicArray class makes use of 8 bits to represent 1
 and 8 bits to represent 0, which we must fix without forcing end users to choose a different DynamicArray class that works efficiently for bool.
 */
template<class T>
class DynamicArray
{
private:
    deque<T> dynamicArray;  // use of STL deque as internal container
    /* an iterator for deque is declared with the name, pos.
     This iterator, pos, is utilized by the Dynamic template class to provide high-level methods
     such as the initialize(), appendValue(), hasNextValue(), and getValue() methods. */
    typename deque<T>::iterator pos;
    
public:
    DynamicArray()
    {
        initialize();
    }
    ~DynamicArray()
    {
    }

    
    
    void initialize()
    {
        pos = dynamicArray.begin();  // init pos to deque begin
    }
    
    void appendValue(T element)  // push back
    {
        dynamicArray.push_back(element);
    }
    
    bool hasNextValue()  // is end?
    {
        return (pos != dynamicArray.end());
    }
    
    T getValue()  //*pos++
    {
        return *pos++;
    }
    
};

/* fix the performance design issue for bool type */
template<>
class DynamicArray<bool>  // Explicit class specializations, explicit template specialization replaces the primary template class with its own complete definitions for a specific data type.
{
private:
    /* deque of bitsets of 8 bits, and, when required,
     deque will automatically allocate more bitset<8> bits.
     The bitset variable is a memory-efficient STL container that consumes just 1 bit
     to represent true or false. */
    //declaring dynamicArray with every element is capacity of 8 bits 00000000
    deque<bitset<8> *> dynamicArray;
    typename deque<bitset<8>*>::iterator pos;
    int bitSetIndex;
    
    int getDequeIndex()
    {
        return (bitSetIndex) ? (bitSetIndex/8):0;  // get bitset<8> element index
    }
    
public:
    DynamicArray() {
        bitSetIndex = 0;
        initialize();
    }
    
    ~DynamicArray() { }
    
    void initialize() {
        pos = dynamicArray.begin();
        bitSetIndex = 0;  // init bitSetIndex to 0
    }
    
    void appendValue(bool value){
        int dequeIndex = getDequeIndex();
        bitset<8> *pBit = NULL;
        
        // if not enough space, create 8 bit more new space
        if((dynamicArray.size() == 0) || (dequeIndex >= (dynamicArray.size()))){
            pBit = new bitset<8>;  //pBit point to new bitset<8>
            pBit->reset();
            dynamicArray.push_back(pBit);
        }
        
        if( !dynamicArray.empty()){
            pBit = dynamicArray.at(dequeIndex);  // point to free bitset<8>
        }
        
        //bitwise AND
        pBit->set( bitSetIndex % 8, value);  // set value at poistion bitSetIndex % 8
        ++bitSetIndex;
    }
    
    bool hasNextValue(){
        return (bitSetIndex<((dynamicArray.size()*8)));  //dynamicArray element is bitset<8>
    }
    
    bool getValue(){
        int dequeIndex = getDequeIndex();
        bitset<8> *pBit = dynamicArray.at(dequeIndex);
        int index = bitSetIndex % 8;  //offset % 8
        ++bitSetIndex;
        
        return (*pBit)[index] ? true : false;
    }
    
};



int main () {
    
    DynamicArray<int> intArray;
    
    intArray.appendValue( 100 );
    intArray.appendValue( 200 );
    intArray.appendValue( 300 );
    intArray.appendValue( 400 );
    
    intArray.initialize();
    
    cout << "\nInt DynamicArray values are ..." << endl;
    while ( intArray.hasNextValue() )
        cout << intArray.getValue() << "\t";
    cout << endl;
    
    DynamicArray<char> charArray;
    charArray.appendValue( 'H' );
    charArray.appendValue( 'e' );
    charArray.appendValue( 'l' );
    charArray.appendValue( 'l' );
    charArray.appendValue( 'o' );
    
    charArray.initialize();
    
    cout << "\nChar DynamicArray values are ..." << endl;
    while ( charArray.hasNextValue() )
        cout << charArray.getValue() << "\t";
    cout << endl;
    
    DynamicArray<bool> boolArray;
    
    boolArray.appendValue ( true );
    boolArray.appendValue ( false );
    boolArray.appendValue ( true );
    boolArray.appendValue ( false );
    
    boolArray.appendValue ( true );
    boolArray.appendValue ( false );
    boolArray.appendValue ( true );
    boolArray.appendValue ( false );
    
    boolArray.appendValue ( true );
    boolArray.appendValue ( true);
    boolArray.appendValue ( false);
    boolArray.appendValue ( false );
    
    boolArray.appendValue ( true );
    boolArray.appendValue ( true);
    boolArray.appendValue ( false);
    boolArray.appendValue ( false );
    
    boolArray.initialize();
    
    cout << "\nBool DynamicArray values are ..." << endl;
    while ( boolArray.hasNextValue() )
        cout << boolArray.getValue() ;
    cout << endl;
    
    return 0;
    
}
