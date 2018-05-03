/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Vector.hpp"

Point Point::AddVector(Vector v)
{
  Point p2;
  p2.x = x + v.x;
  p2.y = y + v.y;

  return p2;
}

