#include<bits/stdc++.h>
using namespace std;
// #define long long ll 
long addModulo(long a, long b, long m) {
    if (b == 0) return 0;
    long halfAns = addModulo(a, b/2, m);

    if (b%2 == 0) return (halfAns + halfAns)%m;
    else return (halfAns + halfAns + a)%m;
}
int main() {
long long a,b,m;
cin>>a>>b>>m;
cout<<addModulo(a,b,m);
    return 0;
}
