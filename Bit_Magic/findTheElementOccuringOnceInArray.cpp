#include <iostream>
using namespace std;
int main()
{

    int arr[7] = {2, 4, 6, 3, 4, 6, 2};
    int x = 0;
    for (int i = 0; i < 7; ++i)
    {
        x ^= arr[i];
    }
    cout << x << endl;

    return 0;
}