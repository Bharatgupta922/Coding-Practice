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

public:
    void display()
    {
        cout << name << endl;
    }
    void studentSetName(string iname)
    {
        setName(iname);
    }
};
class GStudent : public Student
{
public:
    void setGStudentName(string iname)
    {
        studentSetName(iname);
    }
};
int main()
{
    GStudent bharat;
    bharat.setGStudentName("Bharat Gupta");
    bharat.display();

    return 0;
}