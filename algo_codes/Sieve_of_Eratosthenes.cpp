// Sieve of Eratosthenes
// Last Updated: 11-06-2020
// Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

// Example:

// Input : n =10
// Output : 2 3 5 7

// Input : n = 20
// Output: 2 3 5 7 11 13 17 19
// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void printPrimes(int n)
{
    if (n > 1)
    {
        bool *primes = new bool[n + 1];
        for (int i = 0; i <= n; ++i)
        {
            primes[i] = true;
        }
        primes[0] = primes[1] = false;
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (primes[i] == true)
            {
                for (int j = 2; i * j <= n; ++j)
                {
                    primes[i * j] = false;
                }
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (primes[i] == true)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        printPrimes(n);
    }
    return 0;
}