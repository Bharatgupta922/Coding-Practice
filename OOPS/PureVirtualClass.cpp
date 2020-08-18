#include <iostream>
using namespace std;
//pure virtual functions are those functions which 
//has to be defined in the derived classes 

//all the derived classes from a parent class which has 
//pure virtual function should override the pure virtual function
class Person
{
public:
    virtual void introduce() = 0; // syntax to make the pure virtual functions 
};

//we cannot define the pure virtual finction in the class 
//but we can define them outside the class 
//using scope resolution operator 

void Person ::introduce()
{
    cout << "Hello , from Person" << endl;
}
class Student : public Person
{
public:
    void introduce()
    {
        cout << "hello from Student" << endl;
        Person ::introduce();
    }
};
int main()
{
    Student bharat;
    bharat.introduce();
    return 0;
}