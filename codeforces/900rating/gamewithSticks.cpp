#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)
int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int n,m;
cin>>n>>m;
if(n>m){
	swap(n,m);
}
if(n%2 == 0)cout<<"Malvika";
else cout<<"Akshat";
    return 0;
}
