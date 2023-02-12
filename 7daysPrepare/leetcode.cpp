#include <bits/stdc++.h>
using namespace std;
// balanced or not paranthesis

    string getstring(int i , int j , string s){
        if (i > j)return NULL;
            return s.substr(i,j-i+1); 
    }
    int minimumPartition(string s, int k) {
        int i =  0 , j =  0 ;
        int count =  0;
        while(j<s.length()){
            if(stoi(getstring(i,j,s)) <= k){
                j++;
            } else {
                if(i == j){
                    return -1;
                }
                i = j;
								cout<<"this is it"<<i<<","<<j<<endl;
                count++;
            }
            if(j == s.length()){
                if(stoi(getstring(i,j,s)) <= k){
									count++;
								return count;
								}
                else return -1;
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
string s;
int k;
cin>>s>>k;
cout<<minimumPartition(s,k);

    return 0;
}
