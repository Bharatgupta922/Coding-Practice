#include <iostream>
using namespace std;
//this is diamond problem
class Animal
{
public:
    Animal()
    {
        cout << "Animal constructor " << endl;
    }
    int age;
    void walk()
    {
        cout << "animal Walks" << endl;
    }
};
class Tiger : public Animal
{
public:
    Tiger()
    {
        cout << "Tiger constructor " << endl;
    }
};
class Lion : public Animal
{
public:
    Lion()
    {
        cout << "Lion Constructor" << endl;
    }
};
class Liger : public Tiger, public Lion
{
public:
    Liger()
    {
        cout << "Liger constructor" << endl;
    }
};
int main()
{
    Liger bharat;
    bharat.walk(); /// here compiler will show ambiguity
                   //// it means liger class is inheriting from tiger and lion class
                   /// and both has walk function which is inheriting from Animal class
                   /// so compiler do not know from which class to execute the walk function

    //so we have to put virtual on the before inheriting the animal to tiger and lion
    //Virtual inheritance solves the classic “Diamond Problem”.
    /// It ensures that the child class gets only a single instance of the common base class.

    ///on virtual class inheritance the constructors will also call differently
    ///first animal > tiger > lion > liger

    return 0;
}