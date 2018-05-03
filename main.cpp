/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chen
 *
 * Created on May 1, 2018, 9:02 PM
 */

#include <cstdlib>
#include "Vector.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Point p;
    p.x = 1;
    p.y = 0;
    
    Vector v;
    v.x = 2;
    v.y = 3;
    
    Point p2 = p.AddVector(v);
    printf("p2.x = %f, p2.y=%f\n", p2.x, p2.y);
    
    return 0;
}

