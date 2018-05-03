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

Point Point::AddVector(Vector v)
{
  Point p2;
  p2.x = x + v.x;
  p2.y = y + v.y;

  return p2;
}
