//in almost complete binary  tree or complete bt
/*

MAX HEAP :
operations      |    time complexities
find max        |       O(1)
Delete max      |       O(logn)
insert          |       O(logn)
increase        |       O(logn)
decrease key    |       O(logn)
\=======================================================================================/
find min        |       O(n/2) = O(n)   {because we have to find in only leaves}
Search          |       O(n)
delete          |       o(n+n) = o(n)

*/
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
#define MAX_limit 20
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Heapify(int A[MAX_limit], int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(A + i, A + largest);
        Heapify(A, largest, n);
    }
}
void Build_Max_Heap(int A[MAX_limit], int n)
{
    for (int i = floor(n / 2) - 1; i >= 0; --i)//floor(n/2)-1 gives the index of last leave
    {
        Heapify(A, i, n);
    }
}
int getMax(int A[MAX_limit], int n)
{
    if (n > 0)
        return A[0];
    return -1;
}
void DeleteMax(int A[MAX_limit], int *n)
{
    if (*n < 1)
    {
        cout << "ERROR! Heap is underflow" << endl;
        return;
    }
    A[0] = A[(*n) - 1];
    (*n)--;
    Heapify(A, 0, *n);
}
void printHeap(int A[MAX_limit], int n)
{
    if (n < 1)
    {
        cout << "ERROR! Heap is Underflow" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void increase_key(int A[MAX_limit], int i, int key)
{
    if (key < A[i])
    {
        cout << "Error! Key is decreasing the value" << endl;
        return;
    }
    A[i] = key;
    while (i != 0 && A[(i - 1) / 2] < A[i])
    {
        swap(A + i, A + ((i - 1) / 2)); //the parent of a[i] is a[i-1/2]
        i = (i - 1) / 2;
    }
}
void insert_key(int A[MAX_limit], int item, int *n)
{
    (*n)++;
    A[(*n) - 1] = INT_MIN;
    increase_key(A, (*n) - 1, item);
}
int main()
{
    int n;
    cin >> n;
    if (n > MAX_limit)
    {
        cout << "Opps ! you have to choose the number below 20" << endl;
    }
    else
    {
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        Build_Max_Heap(A, n);
        printHeap(A, n);
        cout << "The max in Heap = " << getMax(A, n) << endl;
        cout << "After deleting the Max" << endl;
        DeleteMax(A, &n);
        printHeap(A, n);
        cout << "enter the updated number you want and index of that number" << endl;
        int key, index;
        cin >> key >> index;
        increase_key(A, index, key);
        printHeap(A, n);
        cout << "you want to insert in the Heap ,Enter the value" << endl;
        int data;
        cin >> data;
        insert_key(A, data, &n);
        cout << "resultant Heap is :" << endl;
        printHeap(A, n);
    }

    return 0;
}