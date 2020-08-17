// A Diophantine equation is a polynomial equation,
// usually in two or more unknowns, such that only the integral solutions are required.
// An Integral solution is a solution such that all the unknown variables take only integer values.

// Given three integers a, b, c representing a linear equation of the form : ax + by = c.
//  Determine if the equation has a solution such that x and y are both integral values.

//basically you have to find the roots or check if there an be roots or not

// For linear Diophantine equation equations, integral solutions exist if and only if,
// the GCD of coefficients of the two variables divides the constant term perfectly.
// In other words the integral solution exists if, GCD(a ,b) divides c.
#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b, int c)
{
    return c % __gcd(a, b) == 0;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool success = check(a, b, c);
        if (success)
        {
            cout << "possible" << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}