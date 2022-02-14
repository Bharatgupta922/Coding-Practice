#include <iostream>
#include <climits>
using namespace std;
bool isSafe(int *a, int i, int j, int rows, int cols, bool *visited)
{
    return i >= 0 && i < rows && j >= 0 && j < cols && *((a + i * cols) + j) == 1 && (!*((visited + i * cols) + j));
}
int PathUtil(int *a, int i, int j, int x, int y, int rows, int cols, bool *visited)
{
    if (i == x && j == y)
    {
        return 1;
    }
    if (!isSafe(a, i, j, rows, cols, visited))
        return 10000;
    *((visited + i * cols) + j) = true;
    int up = PathUtil(a, i - 1, j, x, y, rows, cols, visited) + 1;
    int down = PathUtil(a, i + 1, j, x, y, rows, cols, visited) + 1;
    int left = PathUtil(a, i, j - 1, x, y, rows, cols, visited) + 1;
    int right = PathUtil(a, i, j + 1, x, y, rows, cols, visited) + 1;
    //backtracking
    *((visited + i * cols) + j) = false;

    return min(min(left, right), min(up, down));
}
int shortestPath(int *a, int i, int j, int x, int y, int rows, int cols)
{
    bool visited[rows][cols];
    return PathUtil(a, i, j, x, y, rows, cols, &visited[0][0]);
}
int main()
{
    int a[5][5] = {{1, 0, 0, 0, 0},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 0, 1},
                   {0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 1}};
    int rows = sizeof(a) / sizeof(a[0]);
    int cols = sizeof(a[0]) / sizeof(a[0][0]);
    cout << "The Shortest path : ";
    int result = shortestPath(&a[0][0], 0, 0, 4, 4, rows, cols);
    if (result >= 10000)
        cout << "no path possible" << endl;
    else
        cout << result << endl;
    return 0;
}