#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "constructor of person class is called " << endl;
    }
    ~Person()
    {
        cout << "Destructor of person class is called " << endl;
    }
};
class Student : public Person
{
public:
    Student()
    {
        cout << "Constructor of Student class is called" << endl;
    }
    ~Student()
    {
        cout << "Destructor of Student class is called" << endl;
    }
};
int main()
{
    Student bharat;
    return 0;
}