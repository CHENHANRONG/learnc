//
//  try_container_set.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/23.
//  Copyright © 2018年 陈含荣. All rights reserved.
//


#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main( ) {
    set<int> s1 = { 1, 3, 5, 7, 9 };  // init set
    set<int> s2 = { 2, 3, 7, 8, 10 };   // init set
    
    vector<int> v( s1.size() + s2.size() );  // init result vector
    
    cout << "\nFirst set values are ..." << endl;
    copy ( s1.begin(), s1.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    cout << "nSecond set values are ..." << endl;
    copy ( s2.begin(), s2.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    /* The set_difference() algorithm will populate the vector v with values only present in set s1 but not in s2. The iterator, pos, will point to the last element in the vector; hence, the vector resize will ensure that the extra spaces in the vector are removed: */
    /* prototype of set_difference function:
     template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
     inline _LIBCPP_INLINE_VISIBILITY
     _OutputIterator
     set_difference(_InputIterator1 __first1, _InputIterator1 __last1,
     _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
     */
    auto pos = set_difference ( s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin() );
    v.resize ( pos - v.begin() );  //resize to remove the extra spaces
    
    cout << "\nValues present in set one but not in set two are ..." << endl;
    copy ( v.begin(), v.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    v.clear();  //clear
    
    v.resize ( s1.size() + s2.size() );  //resize
    
    // merge two sets as union
    /* The set_union() algorithm will merge the contents of sets s1 and s2 into the vector, and the vector is then resized to fit only the merged values: */
    /* prototype of set_union function:
     template <class _InputIterator1, class _InputIterator2, class _OutputIterator>
     inline _LIBCPP_INLINE_VISIBILITY
     _OutputIterator
     set_union(_InputIterator1 __first1, _InputIterator1 __last1,
     _InputIterator2 __first2, _InputIterator2 __last2, _OutputIterator __result)
     */
    pos = set_union ( s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin() );
    
    v.resize ( pos - v.begin() );
    
    cout << "\nMerged set values in vector are ..." << endl;
    copy ( v.begin(), v.end(), ostream_iterator<int> ( cout, "\t" ) );
    cout << endl;
    
    return 0;
}
