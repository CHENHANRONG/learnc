/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include<list>
#include<algorithm>
#include<iterator>


/* The list STL container makes use of a doubly linked list data structure internally. 
 * Hence, a list supports only sequential access, 
 * and searching a random value in a list in the worst case may take O(N) runtime complexity. 
 * However, if you know for sure that you only need sequential access, 
 * the list does offer its own benefits. 
 * The list STL container lets you insert data elements at the end, 
 * in the front, or in the middle with a constant time complexity,
 * that is, O(1) runtime complexity in the best, average, and worst case scenarios. */

using namespace std;


int main()
{
    list<int> l;
    for(int count=0;count<5;++count)
    {
        l.push_back((count+1)*100);
    }
    
    auto pos = l.begin();
    cout<<"\nPrint the list ..."<<endl;
    while(pos != l.end())
        cout<< *pos++ << "-->";
    cout<<" X"<<endl;
    
    l = { 100, 20, 80, 50, 60, 5 };
    pos = l.begin();
    cout << "\nPrint the list before sorting ..." << endl;
    copy ( l.begin(), l.end(), ostream_iterator<int>( cout, "-->" ));
    cout << "X" << endl;

    l.sort();

    cout << "\nPrint the list after sorting ..." << endl;
    copy ( l.begin(), l.end(), ostream_iterator<int>( cout, "-->" ));
    cout << "X" << endl; 
    
    return 0;
}
