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

//public inheritance
class Student : public Person
{

    // all the public members of the Parent class will act as public members of this class
    // all the protected members of the Parent class will act as protected members of this class
    // but the private members of Parent class is not accessible in this child / derived class

public:
    void display()
    {
        cout << name << endl;
    }
};
int main()
{

    Student bharat;
    //bharat.name = "Bharat"; // it will give you the error .
    //b/c it is also the protected member of Student class as it inherites from Person class .
    bharat.setName("Bharat Gupta");
    bharat.display();
    return 0;
}