#include<bits/stdc++.h>
using namespace std;
int main () {
int t;
cin>>t;
while(t--) {
    int w,h,n;
    cin>>w>>h>>n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i =0; i < n; ++i){
        cin>>x[i];
        cin>>y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (n == 0) {
        cout<<w*h<<endl;
    } else {
        int x_gap = max(x[0]-1, w-x.back());
        int y_gap = max(y[0]-1, h-y.back());
        for (int i =1; i < n ; ++i){
            x_gap = max(x_gap, x[i]- x[i-1]-1);
            y_gap = max(y_gap, y[i]-y[i-1]-1);
        }
        cout<<y_gap*x_gap<<endl;
    }
}

    return 0;
}