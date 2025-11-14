#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t ;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        vector<int> ip(n);
        int gc = 0;
        for (int i = 0 ;  i < n ; ++i)
        {
            cin>>ip[i];
            gc = __gcd(ip[i], gc);
        }
        if (gc == 1) cout<<"0"<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}