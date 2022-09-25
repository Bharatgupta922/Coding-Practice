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
int a[n];
f(i,n)cin>>a[i];
// find pivot 
int s = 0 , e = n-1;
int mid = s+ (e-s)/2;
while(s<e){
	if(a[mid] >= a[0])
	s = mid + 1;
	else e  =mid;
	mid = s+(e-s)/2;
}
cout<<s;

    return 0;
}