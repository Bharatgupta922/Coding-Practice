#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isSafe(int *a, int i, int j, int rows, int cols, bool *visited)
{
    return i >= 0 && i < rows && j >= 0 && j < cols && *((a + i * cols) + j) == 1 && (!*((visited + i * cols) + j));
}
bool PathUtil(int *a, int i, int j, int x, int y, int rows, int cols, string s, bool *visited, vector<string> &vec)
{
    if (!isSafe(a, i, j, rows, cols, visited))
    {
        return false;
    }
    if (i == x && j == x)
    {
        vec.push_back(s);
        return true;
    }
    *((visited + i * cols) + j) = true;
    bool down = PathUtil(a, i + 1, j, x, y, rows, cols, s + 'D', visited, vec);
    bool left = PathUtil(a, i, j - 1, x, y, rows, cols, s + 'L', visited, vec);
    bool right = PathUtil(a, i, j + 1, x, y, rows, cols, s + 'R', visited, vec);
    bool up = PathUtil(a, i - 1, j, x, y, rows, cols, s + 'U', visited, vec);
    *((visited + i * cols) + j) = false;
    if (!s.empty())
        s.pop_back();
    return up || down || left || right;
}
vector<string> paths(int *a, int i, int j, int x, int y, int rows, int cols)
{
    bool visited[rows][cols];
    vector<string> vec;
    bool success = PathUtil(a, i, j, x, y, rows, cols, "", &visited[0][0], vec);
    sort(vec.begin(), vec.end());
    return vec;
}
int main()
{
    int n = 5;
    int a[n][n] = {{1, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 0, 1},
                   {0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 1}};
    int rows = sizeof(a) / sizeof(a[0]);
    int cols = sizeof(a[0]) / sizeof(a[0][0]);
    vector<string> vec = paths(&a[0][0], 0, 0, n - 1, n - 1, rows, cols);
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}