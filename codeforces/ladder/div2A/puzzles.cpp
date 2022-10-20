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

int n , m  ;
cin>>n>>m;
int a[m];
int mn = INT_MAX,mx = INT_MIN;
for(int i = 0 ;  i < m ; ++i){
	cin>>a[i];
	if(i <= n-1){
		mn = min(mn,a[i]);
		mx = min(mx,a[i]);
	}

}
    return 0;
}