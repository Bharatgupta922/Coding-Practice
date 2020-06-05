// ques of geeks for geeks
// naive solution is sort and then print O(nlogn)
//second solution is max-heap and in which building an bt is O(n) and  pop k elements which is O(klogn)
//overall O(n + klogn)

/*1

1. Build a min heap, and start inserting the elements into it.
2. If heap size becomes equal to K, then compare the incoming element with the element at the top of the heap.
3. If element at the top is less than the incoming element, then pop the top from heap and insert the new element into the heap.
4. Finally, you are having K largest elements in the heap. Now, since you need to print the elements in decreasing order, so you can now pop the elements from heap one by one and store it in a vector.
5. Print the elements in the vector in reverse order.

Time Complexity :
O(k+(n-k)logk)
*/
#include <iostream>
using namespace std;
#include <queue>
#include <vector>
void printNLargest(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(a[i]);
    for (int i = k; i < n; i++)
    {
        if (a[i] > pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << *it << " ";
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
        printNLargest(a, n, k);
    }
    return 0;
}