#include <iostream>
using namespace std;
class Person
{
private:
    int age;

public:
    void setAge(int age)
    {
        //  age = age;  //     this will give you the error , but
        this->age = age;
    }
    void display()
    {
        cout << "the age is " << this->age << endl;
    }
};
int main()
{
    Person bharat;
    bharat.setAge(18);
    bharat.display();
    return 0;
}