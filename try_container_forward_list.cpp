//
//  try_container_forward_list.cpp
//  learnc
//
//  Created by hanrong chen on 6/21/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include <iostream>
#include<forward_list>
#include<iterator>
#include<algorithm>
using namespace std;

int main ( )
{
    forward_list<int> list1 = { 10, 20, 10, 45, 45, 50, 25 };
    forward_list<int> list2 = { 20, 35, 27, 15, 100, 85, 12, 15 };
    cout << "\nFirst list before sorting ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    cout << "\nSecond list before sorting ..." << endl;
    copy ( list2.begin(), list2.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    
    list1.sort(); //sort list
    list2.sort();
    cout << "\nFirst list after sorting ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    cout << "\nSecond list after sorting ..." << endl;
    copy ( list2.begin(), list2.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    
    list1.merge ( list2 );  //merge
    cout << "\nMerged list ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << "\nSize of list with duplicates is " << distance( list1.begin(), list1.end() ) << endl;
    list1.unique();  //remove duplicate
    cout << "\nSize of list without duplicates is " << distance( list1.begin(), list1.end() ) << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << "\nlist after removing duplicates and before resize..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    list1.resize( distance( list1.begin(), list1.end() ) );  //resize the list
    cout << "\nlist after removing duplicates and after resize..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    
    return 0;

}

