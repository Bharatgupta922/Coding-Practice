#include <iostream>
using namespace std;
class Person
{
public:
    void introduce()
    {
        cout << "Hey i am a person " << endl;
    }
};
class Student : public Person
{
public:
    void introduce()
    {
        cout << "hey is am a Student " << endl;
        Person::introduce();
        //if you want to access the access the overridden method in derived class
    }
};
int main()
{
    Student bharat;
    bharat.introduce();
    bharat.Person::introduce();
    //if you want to access the access the overridden method using object
    return 0;
}