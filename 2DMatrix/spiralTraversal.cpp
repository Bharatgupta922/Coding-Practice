#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    int b[m * n];
    int dir = 0, y = 0;
    int top = 0, down = m - 1, left = 0, right = n - 1;
    while (top <= down && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
                b[y++] = a[top][i];
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= down; i++)
                b[y++] = a[i][right];
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                b[y++] = a[down][i];
            down--;
        }
        else
        {
            for (int i = down; i >= top; i--)
                b[y++] = a[i][left];
            left++;
        }
        dir = (dir + 1) % 4;
    }
    for (int i = 0; i < y; i++)
        cout << b[i] << "\n";
    return 0;
}
