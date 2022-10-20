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
int n , m ;
cin>>n>>m;
int a[m];
for(int i = 0  ; i < m ; ++i)
cin>>a[i];
int ans = INT_MAX ; 
sort(a,a+m);
for(int i = 0 ;  i < m - n + 1; ++i){
	int x = a[i];
	int y = a[i+n-1];
ans = min(ans,abs(x-y));
}
cout<<ans;
    return 0;
}