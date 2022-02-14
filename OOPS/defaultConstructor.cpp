#include <iostream>
using namespace std;
class Man
{
private:
    string name;
    int age;

public:
    //default arguments
    Man(string iname = "no name", int iage = 0) // overloaded
    {
        cout << "This is a overloaded default constructor constructor" << endl;
        name = iname;
        age = iage;
    }
    void speakup()
    {
        cout << name << endl
             << age << endl;
    }
};
int main()
{
    Man bharat("bharat Gupta", 24);
    bharat.speakup();
    return 0;
}
