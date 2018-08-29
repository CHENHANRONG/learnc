#include <iostream>
#include <string>
#include <list>
using namespace std;

class IEmployee
{
  private:
    string firstName, middleName, lastName;
    string title;
    string employeeCode;
    list<IAddress> addresses;
    list<IContact> contactNumber;

  public:
    virtual string getAddress() = 0;
    virtual string getContractNumber() = 0;
};

class IAddress
{
  private:
    string doorNo, street, city, pinCode, state, country;

  public:
    IAddress(string doorNo, string street, string _city,
             string pinCode, string state, string country) : doorNo(doorNo), street(street),
                                                             city(city), pinCode(pinCode), state(state), country(country);

    virtual string getAddress() = 0;
};

class IContact
{
  private:
    string countryCode, mobileNumber;

  public:
    IContact(string countryCode, string mobileNumber) : countryCode(countryCode, 
    mobileNumber(mobileNumber);
    virtual string getMobileNumber() = 0;
};

// virtual string getDoor() = 0;
// virtual string getStreet() = 0;
// virtual string getCity() = 0;
// virtual string getPinCode() = 0;
// virtual string getState() = 0;
// virtual string getCountry() = 0;
// virtual string getName() = 0;
// virtual string getTitle() = 0;
// virtual string getCountryDialCode() = 0;
// virtual string getContactNumber() = 0;
