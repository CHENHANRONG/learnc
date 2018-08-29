/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.hpp
 * Author: chen
 *
 * Created on May 1, 2018, 10:03 PM
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdio>

class Vector
{
  public:
    float x,y;
};

class Point{
  public:
    Point AddVector(Vector v);
    float x,y;
};


#endif /* VECTOR_HPP */

