#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
using namespace std;
int fibonnaci(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return fibonnaci(n - 1) + fibonnaci(n - 2);
}
void ques2()
{
    long long int sum = 0, i = 1;
    while (sum < 4000000)
    {
        if (fibonnaci(i) % 2 == 0)
            sum += fibonnaci(i);
        i++;
    }
    cout << sum;
}
void ques3()
{
    long long int max = INT_MIN, n = 63;
    for (long long int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            if (max < i)
                max = i;
            n /= i;
        }
    }
    cout << max << endl;
}
void ques4()
{
}
bool check(long long int n)
{
    for (int i = 2; i <= 20; i++)
        if (n % i != 0)
            return false;
    return true;
}
void ques5()
{
    for (long long int i = 21;; i++)
    {
        if (check(i))
        {
            cout << i;
            break;
        }
    }
}

// void ques6(){
//  long long int sum1  = pow((100*(100-1))/2,2);
//  long long int sum2 =  (100 * (100 -1) * (2*100 -1))/6;
//  cout<<sum2-sum1;
// }
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void ques7()
{
    int count = 0, i = 2, result;
    while (1)
    {
        if (isPrime(i))
        {
            result = i;
            count++;
        }
        i++;
        if (count == 10001)
            break;
    }
    cout << result;
}
void ques8()
{
    string s = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    int product = INT_MIN;
    for (int i = 0; i < s.length() - 13; i++)
    {
        int temp = 1;
        for (int j = i; j < i + 13; j++)
            temp *= (s[j] - 48);
        if (product < temp)
            product = temp;
    }
    cout << product << endl;
}
void ques9()
{
    int n = 1000;
    for (int i = 1; i <= n / 3; i++)
    {
        for (int j = i + 1; j <= n / 2; j++)
        {
            int k = n - i - j;
            if (i * i + j * j == k * k)
            {
                cout << i << " " << j << " " << k << " " << endl
                     << " product is " << i * j * k;
                break;
            }
        }
    }
}
void ques10()
{
    long long int n = 2000000, sum = 0;
    for (int i = 2; i < n; i++)
        if (isPrime(i))
            sum += i;
    cout << sum << endl;
}
// void ques11(){
//     int a[20][20];
//     for(int i=0;i<20;i++)for(int j = 0;j<20;j++)cin>>a[i][j];
//     long long int sum1 = INT_MIN;
//     int count = 0;
//     for(int i=0;i<20;i++){
//         for(int j=0;j<20;j++){
//           temp+=a[i][j];
//           count++;
//           if(count == 4){
//               count = 0;
//               temp = 0;
//           }
//         }
//     }

//     count = 0;
//     for(int i=0;i<20;i++){
//         for(int j=0;j<20;j++){
//           temp+=a[j][i];
//           count++;
//           if(count == 4){
//               count = 0;
//               temp = 0;
//           }
//         }
//     }

// }
long long int factorial(long long int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
void ques20()
{
    long long int fact = factorial(100), result = 0;
    cout << fact << endl;
    while (fact > 0)
    {
        long long int b = fact % 10;
        result += b;
        fact /= 10;
    }
    cout << result << endl;
}
int main()
{
    // C++
    ques20();
    return 0;
}
