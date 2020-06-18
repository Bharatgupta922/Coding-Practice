#include <iostream>
using namespace std;
// constructors are generally used to initialise the members of the class
//constructors is called when a object is made
class Man
{
private:
    string name;
    int age;

public: /// we have to make the constructor public otherwise we will not able to access from outside the class
    Man()
    { // constructor do not have return type
        name = "no name ";
        age = -1;
        cout << "Constructor is called when you create object of the class " << endl;
    }
    void display()
    {
        cout << "Your name is " << name << endl;
        cout << "Your age is " << age << endl;
    }
    void setName(string value)
    {
        name = value;
    }
    void setAge(int value)
    {
        age = value;
    }
};
int main()
{
    Man bharat;
    bharat.display();
    cout << "-------------=================---------------------=============" << endl;
    bharat.setAge(19);
    bharat.setName("Bharat Gupta");
    bharat.display();
    return 0;
}