#include <iostream>
using namespace std;
class Man
{
private:
    string *name;
    int *age;

public:
    Man(string iname, int iage)
    {
        name = new string;
        age = new int;

        *name = iname;
        *age = iage;
        cout << "constructor called and memory allocated" << endl;
    }
    void display()
    {
        cout << "Hi i am " << *name << " i am " << *age << " years old" << endl;
    }
    ~Man()
    {
        delete name;
        delete age;
        cout << "All memory is released" << endl;
    }
};
int main()
{
    Man *bharat = new Man("Bharat Gupta", 19);
    bharat->display();
    delete bharat;
    return 0;
}