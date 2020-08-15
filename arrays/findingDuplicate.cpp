#include <bits/stdc++.h>
using namespace std;
//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
// find the duplicate one.
int findDuplicate(vector<int> &vec)
{
    int slow = vec[0];
    int fast = vec[0];
    do
    {
        slow = vec[slow];
        fast = vec[vec[fast]];
    } while (slow != fast);

    fast = vec[0];

    while (slow != fast)
    {
        slow = vec[slow];
        fast = vec[fast];
    }
    return slow;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    int ip;
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    cout << findDuplicate(vec);
    return 0;
}