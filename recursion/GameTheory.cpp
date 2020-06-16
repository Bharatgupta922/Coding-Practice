#include <iostream>
using namespace std;
int GameTheory(int a[], int l, int r)
{
    if (l + 1 == r)
    {
        return max(a[l], a[r]);
    }
    return max(a[l] + min(GameTheory(a, l + 1, r - 1), GameTheory(a, l + 2, r)),
               a[r] + min(GameTheory(a, l, r - 2), GameTheory(a, l + 1, r - 1)));
}

int main()
{
    int a[] = {1, 5, 700, 2};
    cout << GameTheory(a, 0, 3);
    return 0;
}