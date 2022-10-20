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
int t;
cin>>t;
	int a,b,c;
while(t--){
	cin>>a>>b>>c;
	int x = abs(b-c) + abs(c-1);
	int y = a == 1 ? 0 : a - 1;
	if(x == y)cout<<"3";
	else if(y<x)cout<<"1";
	else cout<<"2";
	cout<<endl;
}

    return 0;
}