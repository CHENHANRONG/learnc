//
//  try_google_test_framework_tobetest.cpp
//  learnc
//
//  Created by hanrong chen on 7/16/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
//

#include "try_google_test_framework_tobetest.hpp"
#include "MathFactory.hpp"


int Math::add(int firstInput, int secondInput){
    return firstInput+secondInput;
}

RPNCalculator::RPNCalculator() {
    strMathOperators = "+-*/";
}

bool RPNCalculator::isMathOperator(string strMathOperator) {
    return strMathOperators.find(strMathOperator) != string::npos;
}

double RPNCalculator::evaluate(string rpnMathExpression) {
    MathOperator *pMathOperator = MathFactory::getMathObject();
    
    stack<double> numberStack;
    stringstream rpnMathTokens(rpnMathExpression);
    istream_iterator<string> begin(rpnMathTokens);
    istream_iterator<string> end;
    vector<string> rpnTokens(begin,end);
    vector<string>::iterator pos = rpnTokens.begin();
    
    double firstNumber, secondNumber, result;
    
    while(pos != rpnTokens.end()){
//        cout<<"*pos = "<<*pos<<endl;
//        printf("*pos = %s\n", (*pos).c_str());
        if(isMathOperator(*pos)){
            secondNumber = numberStack.top();
            numberStack.pop();
            firstNumber = numberStack.top();
            numberStack.pop();
            
            pMathOperator = MathFactory::getMathOperator(*pos);
            result = pMathOperator->evaluate(firstNumber, secondNumber);
            result = firstNumber + secondNumber;
            numberStack.push(result);
        }else{
            numberStack.push(std::stod(*pos));
        }
        
        ++pos;
    }
        
//        if(*pos == "+"){
//            firstNumber = numberStack.top();
//            numberStack.pop();
//            secondNumber = numberStack.top();
//            numberStack.pop();
//            result = firstNumber + secondNumber;
//            numberStack.push(result);
//        }else if(*pos == "*"){
//            firstNumber = numberStack.top();
//            numberStack.pop();
//            secondNumber = numberStack.top();
//            numberStack.pop();
//            result = firstNumber * secondNumber;
//            numberStack.push(result);
//        }else if(*pos == "-"){
//            firstNumber = numberStack.top();
//            numberStack.pop();
//            secondNumber = numberStack.top();
//            numberStack.pop();
//            result = secondNumber - firstNumber;
//            numberStack.push(result);
//        }else if(*pos == "/"){
//            firstNumber = numberStack.top();
//            numberStack.pop();
//            secondNumber = numberStack.top();
//            numberStack.pop();
//            if(firstNumber - 0.0< 0.00000000001){
//                fprintf(stderr,"Dividen number is zero\n");
//            }else{
//                result = secondNumber / firstNumber;
//                numberStack.push(result);
//            }
//        }else{
//            numberStack.push(std::stod(*pos));
//        }
//
//        ++pos;
//    }
    
    return numberStack.top();
}
