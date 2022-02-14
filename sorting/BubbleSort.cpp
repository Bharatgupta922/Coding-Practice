#include "bits/stdc++.h"
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Bubble(int arr[], int n)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}
int BubbleOPTimised(int arr[], int n)
{

    for (int i = 0; i < n - 1; ++i)
    {
        bool CheckAnySwap = true;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j + 1], &arr[j]);
                CheckAnySwap = false;
            }
        }
        if (CheckAnySwap)
            break;
    }
}
void printTheArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int32_t main()
{

    int arr[] = {5, 8, 9, 4, 6, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleOPTimised(arr, n);
    printTheArray(arr, n);
    return 0;
}