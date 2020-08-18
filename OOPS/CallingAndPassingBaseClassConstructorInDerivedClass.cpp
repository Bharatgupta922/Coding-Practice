#include <iostream>
using namespace std;
class Person
{
public:
    int height;
    Person(int h)
    {
        cout << "constructor of Person class is called" << endl;
        height = h;
    }
};
class Child
{
public:
    string skinColor;
    Child(string iskinColor)
    {
        cout << "constructor of child class is called";
        skinColor = iskinColor;
    }
};
class Student : public Person, public Child
{
public:
    //pasing calling the constructor of base class in derived class

    Student(string color, int x) : Person(x), Child(color) // this will call the first the constructor of derived class with arguments
                                                           //and then base class's constructor with arguments
    {
        cout << "constructor of base class / Student class is called" << endl;
    }
    void display()
    {
        cout << "height of the person is " << height << " and color of child is " << skinColor << " ." << endl;
    }
};
int main()
{
    Student bharat("brown", 6);
    bharat.display();
    return 0;
}