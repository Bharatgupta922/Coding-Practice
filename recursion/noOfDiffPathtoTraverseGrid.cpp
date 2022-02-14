#include <iostream>
using namespace std;

//basically a grid is given with x  , y dimensions
//we need to find number of paths to get to the bottomMost and rightMost cell of the grid
// the starting point is TopMost and RightMost (0,0) cell of the grid
// you can only move in left or bottom

int noOfPaths(int x, int y)
{
    if (x == 1 || y == 1)
        return 1;
    return noOfPaths(x, y - 1) + noOfPaths(y, x - 1);
}
int main()
{
    int x, y;
    cout << "Enter the dimensions " << endl;
    cin >> x >> y;
    cout << noOfPaths(x, y) << endl;
    return 0;
}
