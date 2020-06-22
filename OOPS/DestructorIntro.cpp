#include <iostream>
using namespace std;
class Man
{
public:
    Man()
    {
        cout << "Constructor is called " << endl;
    }
    ~Man()
    {
        cout << "Destructor is called" << endl;
    }
};
int main()
{
    Man *anil;
    anil = new Man();
    delete anil;

    return 0;
}
