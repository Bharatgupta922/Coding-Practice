#include <iostream>
using namespace std;
#include <queue>
//geeks for geeks ques
void printCount(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);
    int sum = 0, count = -1;
    while (sum < k && !pq.empty())
    {
        sum += pq.top();
        pq.pop();
        ++count;
    }
    cout << count << endl;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        printCount(a, n, k);
    }
    return 0;
}