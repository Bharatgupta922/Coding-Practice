#include <iostream>
using namespace std;
class Man
{
    //by default the members are private in c++
    string name;
    int age;

public:
    Man(string iname, int iage)
    { //constructor
        name = iname;
        age = iage;
    }
    void speakup()
    {
        cout << name << endl
             << age << endl;
    }
    friend void display(Man person); //prototyping
};
void display(Man person)
{
    cout << person.name << endl
         << person.age << endl;
}
int main()
{
    Man bharat("Bharat Gupta", 19);
    display(bharat);
    return 0;
}