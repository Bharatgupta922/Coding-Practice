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
int x;
cin>>x;
if(x>=0){
	cout<<x;
}
else {
	x = -x;
	string a = to_string(x);
	string b = to_string(x);
	a.erase(a.length()-1,1);
	b.erase(b.length()-2,1);
	if(!stoi(a))cout<<stoi(a);
	else if (!stoi(b))cout<<stoi(b);
	else {
		cout<<"-";
	stoi(a) < stoi(b) ? cout<<stoi(a) : cout<<stoi(b); 
	}
}


return 0;
}