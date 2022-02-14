#include <iostream>
#include <vector>
using namespace std;
void printmatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void optimal(int **matrix, int rows, int cols, int col0 = 0)
{
    for (int i = 0; i < rows; ++i)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 1; --j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
    printmatrix(matrix, rows, cols);
}
void brute(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                for (int x = 0; x < rows; ++x)
                {
                    if (matrix[x][j] != 0 && x != i)
                    {
                        matrix[x][j] = -1;
                    }
                }
                for (int x = 0; x < cols; ++x)
                {
                    if (matrix[i][x] && x != j)
                    {
                        matrix[i][x] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    printmatrix(matrix, rows, cols);
}
void booli(int **matrix, int rows, int cols, int col0 = 0)
{
    for (int i = 0; i < rows; ++i)
    {
        if (matrix[i][0] == 1)
            col0 = 1;
        for (int j = 1; j < cols; ++j)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][0] = matrix[0][j] = 1;
            }
        }
    }
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = cols - 1; j >= 1; --j)
        {
            if (matrix[i][0] == 1 || matrix[0][j] == 1)
            {
                matrix[i][j] = 1;
            }
        }
        if (col0 == 1)
        {
            matrix[i][0] = 1;
        }
    }
    printmatrix(matrix, rows, cols);
}
void solve(int **matrix, int rows, int cols)
{
    // brute(matrix, rows, cols);
    // optimal(matrix, rows, cols);
    booli(matrix, rows, cols);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
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
        solve(matrix, m, n);
    }
    return 0;
}