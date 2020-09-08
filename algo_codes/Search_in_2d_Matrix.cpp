#include <iostream>
using namespace std;
//leetcode
bool searchleet(int **matrix, int m, int n, int target)
{
    if (m == 0 && n == 0)
        return false;
    int lo = 0;
    int hi = (m * n) - 1;
    while (lo <= hi)
    {
        int mid = (lo + (hi - lo) / 2);
        if (matrix[mid / n][mid % n] == target)
            return true;
        if (matrix[mid / n][mid % n] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
}
//gfg
bool searchgfg(int **matrix, int m, int n, int target)
{
    if (m == 0 && n == 0)
    {
        return false;
    }
    int i = 0, j = n - 1;
    while (i <= m && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        if (target < matrix[i][j])
        {
            --j;
        }
        else
        {
            ++i;
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int target;
        cin >> target;
        int m, n;
        cin >> m >> n;
        int **matrix = new int *[m];
        for (int i = 0; i < m; ++i)
        {
            matrix[i] = new int[n];
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> matrix[i][j];
            }
        }
        if (searchgfg(matrix, m, n, target))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}