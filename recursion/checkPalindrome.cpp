#include <iostream>
#include<cmath>
using namespace std;
int reverse (int num){
if(num==0)return 0;
return (num%10)*pow(10,(int)log10(num)) + reverse(num/10);
}
bool checkPalindrome(int num)
{
  if(num==reverse(num))return true;
  return false;  
}
int main()
{
    int n;
    cin >> n;
    checkPalindrome(n) ? cout << "Palindrome" : cout << "not palindrome";
    return 0;
}