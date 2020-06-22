#include <iostream>
using namespace std;
class Man
{
public:
    static int count; 
    Man()
    {
        ++count;
    }
  static void TotalMan()
    {
        cout << "there are " << count << "people are in this process " << endl;
    }
};

int Man ::count = 0;
int main()
{
    cout << Man::count;
    Man bharat;
    bharat.TotalMan();
    return 0;
}