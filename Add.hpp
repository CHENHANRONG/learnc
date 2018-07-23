//
//  Add.hpp
//  learnc
//
//  Created by hanrong chen on 7/23/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#ifndef Add_hpp
#define Add_hpp


#include "MathOperator.hpp"

class Add : public MathOperator {
public:
    double evaluate(int,int);
};

#endif /* Add_hpp */
