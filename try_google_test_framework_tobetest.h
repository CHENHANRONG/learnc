//
//  try_google_test_framework_tobetest.hpp
//  learnc
//
//  Created by hanrong chen on 7/16/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#ifndef try_google_test_framework_tobetest_hpp
#define try_google_test_framework_tobetest_hpp

#include <string>
#include <iostream>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;

class Math{
public:
    int add(int,int);
};

class RPNCalculator {
public:
    double evaluate(string);
};


#endif /* try_google_test_framework_tobetest_hpp */
