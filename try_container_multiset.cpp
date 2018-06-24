//
//  try_container_multiset.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/24.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

/* A multiset container works in a manner similar to a set container, except for the fact that a set allows only unique values to be stored whereas a multiset lets you store duplicate values. As you know, in the case of set and multiset containers, the values themselves are used as keys to organize the data. A multiset container is just like a set; it doesn't allow modifying the values stored in the multiset. */
int main( ) {
    set<int> s1 = { 1, 3, 5, 7, 9 };
    set<int> s2 = { 2, 3, 7, 8, 10 };
    
    vector<int> v( s1.size() + s2.size() );
    
    cout << "\nFirst set values are ..." << endl;
    copy ( s1.begin(), s1.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    cout << "\nSecond set values are ..." << endl;
    copy ( s2.begin(), s2.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    auto pos = set_difference ( s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin() );
    v.resize ( pos - v.begin() );
    
    cout << "nValues present in set one but not in set two are ..." << endl;
    copy ( v.begin(), v.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    v.clear();
    
    v.resize ( s1.size() + s2.size() );
    
    pos = set_union ( s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin() );
    
    v.resize ( pos - v.begin() );
    
    cout << "\nMerged set values in vector are ..." << endl;
    copy ( v.begin(), v.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    return 0;
}
