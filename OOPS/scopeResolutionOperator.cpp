#include <iostream>
using namespace std;
class Man
{
public:
    string name = "no Name";
    void introduce();
};

//string Man::name = "Bharat Gupta"<<endl;
//the above line will give the error b/c we can not initialise the attributes of  class
//outside the class if it is not static

//here :: is the Scope Resolution operator
void Man::introduce()
{
    cout << "Hi , My name is " << Man::name << endl;
}
int main()
{
    Man bharat;
    bharat.introduce();
    // if we initialise this
    bharat.name = "Bharat Gupta";
    bharat.introduce();
    return 0;
}