#include <bits/stdc++.h>
using namespace std;
void MaxInWindow(int *a, int k, int n)
{
    deque<int> dq;
    for (int i = 0; i < k; ++i)
    {
        while ((!dq.empty()) && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<a[dq.front()]<<' ';
    for (int i = k; i < n; ++i)
    {
         while ((!dq.empty()) && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while ((!dq.empty()) && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        printf("%d ",a[dq.front()]);
    }
    printf("\n");
}

int main()
{

    int a[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    MaxInWindow(a, k, n);
    return 0;
}