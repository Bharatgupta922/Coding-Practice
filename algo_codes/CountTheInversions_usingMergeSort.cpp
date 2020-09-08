#include <bits/stdc++.h>
using namespace std;
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; ++i)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (left < right)
    {
        //finding mid
        mid = (left + right) / 2;

        //partitioning
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        //merging
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], temp[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            temp[i] = a[i];
        }
        int ans = _mergeSort(a, temp, 0, n - 1);
        cout << ans << endl;
    }
    return 0;
}