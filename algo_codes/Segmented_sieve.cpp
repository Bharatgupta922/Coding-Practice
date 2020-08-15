// actually it is for getting the prime numbrs between a range
// l to r in which l & r are included
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
//sieve of Eratosthenes theorem
vector<int> *sieve()
{
    bool isPrime[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        isPrime[i] = true;
    }
    for (int i = 2; i * i < MAX; ++i)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> *primes = new vector<int>();
    primes->push_back(2);
    for (int i = 3; i < MAX; i += 2)
    {
        if (isPrime[i] == true)
        {
            primes->push_back(i);
        }
    }
    return primes;
}
void printPrimes(long long l, long long r, vector<int> *&primes)
{
    bool isPrime[r - l + 1];
    for (int i = 0; i <= r - l; ++i)
    {
        isPrime[i] = true;
    }
    for (int i = 0; primes->at(i) * (long long)primes->at(i) <= r; ++i)
    {
        int currPrime = primes->at(i);
        //it is to get just previous or equal to multiple of primes of ith index
        long long base = (l / currPrime) * currPrime;
        if (base < l)
        {
            base = base + currPrime;
        }
        //to mark all the multiples of within l to r as false
        for (long long j = base; j <= r; j += currPrime)
        {
            isPrime[j - l] = false;
        }
        // there may be a case in which base itself a prime
        // and you get l/currPrime will be zero
        // so base will become currPrime
        if (base == currPrime)
        {
            isPrime[base - l] = true;
        }
    }
    unsigned long long prod = 1;
    for (int i = 0; i <= r - l; ++i)
    {
        if (isPrime[i] == true)
        {
            cout << i + l << " ";
            prod = ((prod % MOD) * ((i + l) % MOD)) % MOD; // to get the produc of all primes between the ranges l to r
        }
    }
    cout << endl
         << "Here is the product of all prime b/w l to r -> "<< prod << endl;
}
int main()
{
    vector<int> *primes = sieve();
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        printPrimes(l, r, primes);
    }
    return 0;
}