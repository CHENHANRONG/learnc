//
//  MathFactory.hpp
//  learnc
//
//  Created by hanrong chen on 7/23/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#ifndef MathFactory_hpp
#define MathFactory_hpp

#include <string>
#include <map>
using namespace std;

#include "MathOperator.hpp"
#include "Add.hpp"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"


class MathFactory: public MathOperator {
private:
    static map<string, MathOperator*> *static_init_block();
    static map<string, MathOperator*> *pStringToMathObjectMap;
public:
    static MathOperator* getMathObject(string strMathOperator="");
};

#endif /* MathFactory_hpp */
