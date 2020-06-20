#include <iostream>
#include <vector>

using namespace std;
bool Partition(int a[], int sum, int i, int size, vector<int> &vec)
{
    if (i >= size || sum < 0)
        return false;
    if (sum == 0)
        return true;
    vec.push_back(a[i]);
    bool leftPossible = Partition(a, sum - a[i], i + 1, size, vec);
    if (leftPossible)
        return true;

    //this is backtracking
    vec.pop_back();
    return Partition(a, sum, i + 1, size, vec);
}
int main()
{
    int a[] = {2, 1, 2, 3, 4, 8};
    int size = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        sum += a[i];
    vector<int> vec;
    bool isPossible = (sum & 1) == 0 && Partition(a, sum / 2, 0, size, vec);
    if (isPossible)
    {
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            cout << *it << " ";
        }
    }
    else
    {
        cout << "NOT POSSIBLE";
    }
    return 0;
}