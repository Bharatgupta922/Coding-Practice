#include <iostream>
using namespace std;
bool oneDigit(int n)
{
    return n >= 0 && n < 10;
}
bool checkPalindrome(int num, int duplicate)
{
    if (oneDigit(num))
        return true;
}
int main()
{
    int n;
    cin >> n;
    checkPalindrome(n, 0, (int)log10(n)) ? cout << "Palindrome" : cout << "not palindrome";
    return 0;
}