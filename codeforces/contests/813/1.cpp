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
int n ;
cin>>n;

int t ;
while(t--){
	int n , k ;
	cin>>n>>k;
	vector<int> a(n,0);
	f(i,n){
		cin>>a[i];
	}
	
}
    return 0;
}