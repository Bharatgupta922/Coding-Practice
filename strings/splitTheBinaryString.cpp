// Split the binary string into substrings with equal number of 0s and 1s
// Given a binary string str of length N, the task is to find the maximum count of substrings 
// str can be divided into such that all the substrings are balanced i.e. 
// they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
#include<bits/stdc++.h>
using namespace std ;
int main(){
    int t ;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count0 = 0 , count1 = 0 , cnt = 0  ;
        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == '0')++count0;
            else ++count1;
            if(count0  == count1)++cnt;
        }
        cout<<cnt<<endl;
    }
    return 0 ; 
}