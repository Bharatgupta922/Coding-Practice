//dutch national flag problem
// b/c area of zeros is represented by red
// area of ones is represented by white
// area of twos is represented by blue
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mid = 0, low = 0, high = n - 1;

    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}