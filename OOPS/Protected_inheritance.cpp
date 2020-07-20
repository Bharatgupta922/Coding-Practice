#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:
    void setName(string iname)
    {
        name = iname;
    }
};

class Student : protected Person
{

    // all the public members of the Parent class will act as protected members of this class
    // all the protected members of the Parent class will act as protected members of this class
    // but the private members of Parent class is not accessible in this child / derived class

public:
    void setStudentName(string iname)
    {
        setName(iname);
    }
    void display()
    {
        cout << name << endl;
    }
};

int main()
{

    Student bharat;
    //bharat.setName("Bharat Gupta"); //it will give an error
    //b/c it has become the protected member of Student class after inheriting from Person class
    bharat.setStudentName("Bharat Gupta");
    bharat.display();
    return 0;
}