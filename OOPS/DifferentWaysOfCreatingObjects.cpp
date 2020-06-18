#include <iostream>
using namespace std;
class Man
{
public: //access specifiers
    string name;
    void introduce()
    {
        cout << "Hey my name is " << name << endl;
    }
};
int main()
{
    Man bharat;
    Man *Shubham = new Man();
    bharat.name = "Bharat Gupta";
    bharat.introduce();

    Shubham->name = "Shubham Saini";
    Shubham->introduce();
    return 0;
}