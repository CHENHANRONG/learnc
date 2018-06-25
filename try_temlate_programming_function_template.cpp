//
//  try_temlate_programming_function_template.cpp
//  learnc
//
//  Created by hanrong chen on 6/25/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>  //function template
void sort (T input[], int size) {
    for ( int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            if ( input[i] < input[j] )
                swap (input[i], input[j] );
        }
    }
    
}

int main () {
    int a[10] = { 100, 10, 40, 20, 60, 80, 5, 50, 30, 25 };
    
    cout << "\nValues in the int array before sorting ..." << endl;
    copy ( a, a+10, ostream_iterator<int>( cout, "\t" ) );
    cout << endl;
    
    // The scope-resolution operator in front of sort, that is, ::sort(),
    // ensures that it invokes our custom function, sort(), defined in the global namespace;
    // otherwise, the C++ compiler will attempt to invoke the sort() algorithm defined in the std namespace,
    ::sort<int>(a, 10);  //call template function with int
    
    cout << "\nValues in the int array after sorting ..." << endl;
    copy ( a, a+10, ostream_iterator<int>( cout, "\t" ) );
    cout << endl;
    
    double b[5] = { 85.6, 76.13, 0.012, 1.57, 2.56 };
    
    cout << "\nValues in the double array before sorting ..." << endl;
    copy ( b, b+5, ostream_iterator<double>( cout, "\t" ) );
    cout << endl;
    
    
    ::sort<double>(b, 5);  //call template function with double
    
    cout << "\nValues in the double array after sorting ..." << endl;
    copy ( b, b+5, ostream_iterator<double>( cout, "\t" ) );
    cout << endl;
    
    string names[6] = {
        "Rishi Kumar Sahay",
        "Arun KR",
        "Arun CR",
        "Ninad",
        "Pankaj",
        "Nikita"
    };
    
    cout << "\nNames before sorting ..." << endl;
    copy ( names, names+6, ostream_iterator<string>( cout, "\n" ) );
    cout << endl;
    
    ::sort<string>(names, 6);  //call template function with
    
    cout << "\nNames after sorting ..." << endl;
    copy ( names, names+6, ostream_iterator<string>( cout, "\n" ) );
    cout << endl;
    
    return 0;
}
