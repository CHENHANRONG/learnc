//
//  MathOperator.hpp
//  learnc
//
//  Created by hanrong chen on 7/23/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#ifndef MathOperator_hpp
#define MathOperator_hpp

#include <stdio.h>
class MathOperator{
public:
    virtual double evaluate(int, int) = 0;
};
#endif /* MathOperator_hpp */
