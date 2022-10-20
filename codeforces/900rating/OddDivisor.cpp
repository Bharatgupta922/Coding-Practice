#include<bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)
int main(){
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
int t;cin>>t;
while(t--){
	long long n;
	cin>>n;
	if((n&(n-1))==0){
		cout<<"NO";
	}
	else {
		cout<<"YES";
	}
	cout<<endl;
}


return 0;
}