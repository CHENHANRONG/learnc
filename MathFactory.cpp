//
//  MathFactory.cpp
//  learnc
//
//  Created by hanrong chen on 7/23/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include "MathFactory.hpp"



map<string, MathOperator*>* MathFactory::static_init_block(){
    map<string, MathOperator*> *pStringToMathObjectMap = new map<string,MathOperator*>();
    
    pStringToMathObjectMap->insert(make_pair("+", new Add()));
    pStringToMathObjectMap->insert(make_pair("-", new Subtract()));
    pStringToMathObjectMap->insert(make_pair("*", new Multiply()));
    pStringToMathObjectMap->insert(make_pair("/", new Divide()));
    
    return pStringToMathObjectMap;
}

map<string,MathOperator*> * MathFactory::pStringToMathObjectMap = static_init_block();


MathOperator* MathFactory::getMathObject (string typeOfMathObjectRequired) {
    return pStringToMathObjectMap->find(typeOfMathObjectRequired)->second;
}
