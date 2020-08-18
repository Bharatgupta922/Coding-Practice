#include <iostream>
using namespace std;

// The word polymorphism means having many forms. Typically,
// polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

// C++ polymorphism means that a call to a member function will cause a different function
//  to be executed depending on the type of object that invokes the function.

class Person
{
public:
    virtual void introduce()
    {
        cout << "Hello from Person " << endl;
    }
};
class Student : public Person
{
public:
    void introduce()
    {
        cout << "Hello from student " << endl;
    }
};

//no matter how many times it inherited
//virtual nature of introduce function is
//also inherited

class GStudent : public Student
{
public:
};

void whosThis(Person &p)
{
    p.introduce();
}
int main()
{
    Person Rama;
    Student bharat;
    GStudent sam;

    whosThis(Rama);
    whosThis(bharat);
    whosThis(sam);
    return 0;
}