//ques of heap in geeks for geeks
#include <iostream>
using namespace std;
#include <queue> //required header file
void PrintSorted(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; //min heap
    int i = 0;
    for (i = 0; i <= k; i++)
        pq.push(a[i]);
    do
    {
        cout << pq.top() << " ";
        pq.pop();
        pq.push(a[i]);
        i++;
    } while (i < n && !pq.empty());
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
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
        PrintSorted(a, n, k);
    }
    return 0;
}