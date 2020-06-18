#include <iostream>
using namespace std;
class Man
{
private:
    int age;
    int getAge()
    {
        return age - 5; // here we can manipulate the age
    }

public:
    void displayAge()
    {
        cout << getAge() << endl; // if i want to manipulate the age we can manipulate
    }
    void setAge(int value)
    {
        age = value - 5; // or here we can manipulate the given age
    }
};
int main()
{
    Man bharat;
    //bharat.age = "Bharat Gupta";       // b/c i dont want to give access to the user to chang the age
    //bharat.
    bharat.setAge(25);
    bharat.displayAge();

    return 0;
}