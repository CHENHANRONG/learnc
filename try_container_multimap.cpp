//
//  try_container_multimap.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/6/24.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

/* A multimap works exactly as a map, except that a multimap container will allow multiple values to be stored with the same key. */

int main() {
    multimap< string, long > contacts = {
        { "Jegan", 2232342343 },
        { "Meena", 3243435343 },
        { "Nitesh", 6234324343 },
        { "Sriram", 8932443241 },
        { "Nitesh", 5534327346 }
    };
    
    auto pos = contacts.find ( "Nitesh" );
    int count = (int)contacts.count( "Nitesh" );
//    int index = 0;
    
    for(int i=0; i<count && pos != contacts.end(); ++i,++pos){
        cout<<"\nPos ="<<&pos<<endl;
        cout << "\nMobile number of " << pos->first << " is " << pos->second << endl;
    }
    
    return 0;
}
