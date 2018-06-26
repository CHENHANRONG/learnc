//
//  try_temlate_programming_class_template.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/26.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

//myalgorithm.h
#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
using namespace std;

template <typename T, int size>
class MyAlgorithm {
public:
    MyAlgorithm() { }
    ~MyAlgorithm() { }
    
    void sort(array<T, size> &data) {
        for ( int i=0; i<size; ++i ) {
            for ( int j=0; j<size; ++j ) {
                if ( data[i] < data[j] )
                    swap ( data[i], data[j] );
            }
        }
    }
    
    void sort (T data[size]);
    
};

template <typename T, int size>
inline void MyAlgorithm<T, size>::sort (T data[size]) {
    for ( int i=0; i<size; ++i ) {
        for ( int j=0; j<size; ++j ) {
            if ( data[i] < data[j] )
                swap (data[i], data[j]);
        }
    }
}


int main() {
    
    MyAlgorithm<int, 10> algorithm1;
    
    array<int, 10> a = { 10, 5, 15, 20, 25, 18, 1, 100, 90, 18 };
    
    cout << "\nArray values before sorting ..." << endl;
    copy (a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    //
    algorithm1.sort(a);
    
    cout << "\nArray values after sorting ..." << endl;
    copy ( a.begin(), a.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
    
    MyAlgorithm<double, 10> algorithm2;
    double d[] = { 100.0, 20.5, 200.5, 300.8, 186.78, 1.1 };
    
    cout << "\nArray values before sorting ..." << endl;
    //copy (d.begin(), d.end(), ostream_iterator<double>(cout, "\t"));
    cout << endl;
    
    algorithm2.sort(d);
    
    cout << "\nArray values after sorting ..." << endl;
    //copy ( d.begin(), d.end(), ostream_iterator<double>(cout, "\t"));
    cout << endl;
    
    return 0;
    
}
