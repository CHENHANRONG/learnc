//
//  try_google_test_framework_test.cpp
//  learnc
//
//  Created by hanrong chen on 7/16/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//


//#include <stdio.h>.
#include <gtest/gtest.h>
#include "try_google_test_framework_tobetest.hpp"

/* using a TEST macro that takes two parameters.
 The first parameter, namely <XXXTest>, represents the test module name
 and the second parameter is the name of the test case.
 Test modules help us group a bunch of related test cases under a module.
 Hence, it is very important to name the test module and test case
 aptly to improve the readability of the test report.  */

TEST(RPNCalculatorTest, testSimpleAddition ){
    RPNCalculator rpnCalculator;
    double actualResult = rpnCalculator.evaluate ( "10 15 +" );
    double expectedResult = 25.0;
    EXPECT_EQ ( expectedResult, actualResult ); 
}

TEST(MathTest, testAdd){
    Math math;
    int expectedVal = 100;
    int actualVal = math.add(70, 30);

    EXPECT_EQ(expectedVal, actualVal);
}
