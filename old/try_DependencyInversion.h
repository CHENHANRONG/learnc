#include <iostream>

using namespace std;

// class Mobile
// {
//   private:
//     Camera camera;

//   public:
//     Mobile();
//     bool powerOn();
//     bool powerOff();
// };

class Camera
{
  public:
    bool ON();
    bool OFF();
};

/*
In the preceding code, Mobile has implementation-level knowledge about Camera, 
which is a poor design. Ideally, Mobile should be interacting with Camera 
via an interface or an abstract class with pure virtual functions, 
as this separates the Camera implementation from its contract. 
This approach helps replace Camera without affecting Mobile and also 
gives an opportunity to support a bunch of Camera subclasses in place 
of one single camera. 
*/

/*
refactor the preceding code with the DI design principle:
*/

class ICamera
{
  public:
    virtual bool ON() = 0;
    virtual bool OFF() = 0;
};

class Mobile
{
  private:
    ICamera *pCamera;

  public:
    Mobile(ICamera *pCamera);
    void setCamera(ICamera *pCamera);
    bool powerOn();
    bool powerOff();
};
