#include <bits/stdc++.h>
using namespace std;
int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for(int i = 0  ; i < strs[0].length(); ++i){
            for(int j = 1; j < strs.size() ; ++j){
                if(strs[j][i] < strs[j-1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
int main()
{
    // 6
    // 3 2 6 5 0 3

    // #ifndef ONLINE_MODE
    //    freopen("input.txt" , "r", stdin);
    //    freopen("output.txt","w",stdout);
    // #endif
vector<string> s;
int n ;
cin>>n;
for(int i = 0  ; i < n ;  ++i){
	string ip;
	cin>>ip;
	s.push_back(ip);
}
cout<<minDeletionSize(s);
    return 0;
}
