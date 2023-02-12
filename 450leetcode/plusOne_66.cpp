#include <bits/stdc++.h>
using namespace std;
    void plusOne(vector<int>& digits) {
    int i = digits.size()-1, carry = 1 ;
    while(i>=0)
        if((digits[i]+carry)==10){
					carry=1;
					digits[i]=0;
					--i;
					}
					 else {
						digits[i]=digits[i]+carry;
						carry=0;
						--i;
						}
    if(carry>0){
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<ans.size();++i)
        ans[i] = digits[i-1];
}
    }
int main()
{
    // 6
    // 3 2 6 5 0 3

    // #ifndef ONLINE_MODE
    //    freopen("input.txt" , "r", stdin);
    //    freopen("output.txt","w",stdout);
    // #endif
int n;
cin>>n;
vector<int> a(n);
for(int i = 0 ;  i < n ; ++i){
	cin>>a[i];
}
plusOne(a);
    return 0;
}
