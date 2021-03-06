// Given an integer an N. 
// The task is to print the position of 
// first set bit found from right side in the binary representation of the number.

// Input:
// The first line of the input contains an integer T, 
// denoting the number of test cases. Then T test cases follow.
//  The only line of the each test case contains an integer N.

// Output:
// For each test case print in a single line an integer denoting the position of the
//  first set bit found form right side of the binary representation of the number. If there is no set bit print "0".

#include <iostream>
#include<cmath>
using namespace std;

int main() {
    //code
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (n>0)
            cout<<(int)log2(n & -n) + 1<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}