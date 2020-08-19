#include <iostream>
using namespace std;
//abstract classes are those which contains one or more
//pure virtual functions

//you can not make the child object of abstract class

//if you want a class from which you want all derived class should have
//a specific function you make that function pure virtual (or we can say make an abstract class with that functions)

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
    // Person x;
    Student bharat;
    bharat.introduce();
    return 0;
}