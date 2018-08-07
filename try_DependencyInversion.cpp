#include "try_DependencyInversion.h"

//Constructor Dependency Injection
Mobile::Mobile(ICamera *pCamera)
{
    this->pCamera = pCamera;
}

//Method Dependency Injection
void Mobile::setCamera(ICamera *pCamera)
{
    this->pCamera = pCamera;
}

bool Mobile::powerOn()
{
    if (pCamera->ON())
    {
        cout << "\nPositive Logic - assume some complex Mobile power ON logic happens here." << endl;
        return true;
    }
    cout << "\nNegative Logic - assume some complex Mobile power OFF logic happens here." << endl;
    return false;
}

bool Mobile::powerOff()
{
    if (pCamera->OFF())
    {
        cout << "\nPositive Logic - assume some complex Mobile power OFF logic happens here." << endl;
        return true;
    }
    cout << "\nNegative Logic - assume some complex Mobile power OFF logic happens here." << endl;
    return false;
}

// bool Mobile::powerOn()
// {
//     if (camera.ON())
//     {
//         cout << "\nPositive Logic - assume some complex Mobile power ON logic happens here." << endl;
//         return true;
//     }
//     else
//     {
//         cout << "\nNegative Logic - assume some complex Mobile power OFF logic happens here." << endl;
//         return true;
//     }
// }

// bool Mobile::powerOff()
// {
//     if (camera.OFF())
//     {
//         cout << "\nPositive Logic - assume some complex Mobile power OFF logic happens here." << endl;
//         return true;
//     }

//     cout << "nNegative Logic - assume some complex Mobile power OFF logic happens here." << endl;
//     return false;
// }

bool Camera::ON()
{
    cout << "\nAssume Camera class interacts with Camera hardware heren" << endl;
    cout << "\nAssume some Camera ON logic happens here" << endl;
    return true;
}

bool Camera::OFF()
{
    cout << "\nAssume Camera class interacts with Camera hardware heren" << endl;
    cout << "\nAssume some Camera OFF logic happens here" << endl;
    return true;
}
