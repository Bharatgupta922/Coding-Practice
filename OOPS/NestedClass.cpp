#include <iostream>
using namespace std;
//it is nestedly defining the classes
//means defining a class inside another class's definition

//due to variable scope inner class will only be accessible inside the outer(person) class

class Person
{
public:
    string name;
    class Address
    {
    public:
        string country;
        string stname;
        int hno;
    };
    Address addr;
    void AddressPlease()
    {
        cout << name << endl
             << addr.country << endl
             << addr.hno << endl
             << addr.stname << endl;
    }
};
int main()
{
    // Address ad ; //// this will give error b/c it is not in the scope
    //but we can access the Address in this scope using scope resolution operator
    Person ::Address ad;
    ad.country = "Australia";
    Person bharat;
    bharat.name = "Bharat Gupta";
    bharat.addr.country = "India";
    bharat.addr.hno = 512;
    bharat.addr.stname = "uttar pradesh";
    bharat.AddressPlease();
    cout << ad.country;
    return 0;
}