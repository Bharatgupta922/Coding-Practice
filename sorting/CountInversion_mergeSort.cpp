#include "bits/stdc++.h"
using namespace std;
long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - (mid + 1) + 1;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; ++i)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
            inv += n1 - i;
            //a[i] , a[i+1] , a[i+2] , ...... a[n1-1] > b[j] //// b/c both of these two arrays
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
    return inv;
}
long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << mergeSort(arr, 0, n - 1);

    return 0;
}