#include <iostream>
using namespace std;
void studentlist()
{
    class Student
    {
    public:
        int age;
        string name;
        void introduction()
        {
            cout << "hey my name is " << name << " and i am " << age << " years old" << endl;
        }
    };
    Student bharat;
    bharat.age = 18;
    bharat.name = "Bharat Gupta";
    bharat.introduction();
}
int main()
{
    studentlist();
    // Student shubham ; ///// it will give the error and b/c viriable scope do not allow to make
    ////// a object outside the function
    return 0;
}