#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[9] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = arr[0];
    for (int i = 0; i < n; ++i)
    {
        k = max(k, arr[i]);
    }
    int count[k + 1] = {0};
    for (int i = 0; i < n; ++i)
    {
        ++count[arr[i]];
    }
    for (int i = 1; i <= k; ++i)
    {
        count[i] += count[i - 1];
    }
    int result[n];
    for (int i = n - 1; i >= 0; --i)
    {
        result[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
}