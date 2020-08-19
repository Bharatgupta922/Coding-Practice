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
class Student : private Person
{

    // all the public members of the Parent class will act as private members of this class
    // all the protected members of the Parent class will act as private members of this class
    // but the private members of Parent class is not accessible in this child / derived class

    //But if we want to make  members of the parent class which
    //is inherited as private to derived class
    //to the private member of the derived class
    // we can change the access level

public:
    Person ::name;
    Person ::setName;
    void display()
    {
        cout << name << endl;
    }
    void studentSetName(string iname)
    {
        setName(iname);
    }
};
int main()
{

    Student bharat;
    bharat.name = "Bharat Gupta"; //this is private member of student but changed the access level into public member
    bharat.display();
    bharat.setName("Bharat Gupta 2nd input"); //this is private member of student but changed the access level into public member
    bharat.display();
    return 0;
}