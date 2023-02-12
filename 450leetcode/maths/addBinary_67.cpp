#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b) {
        if(a.length()<b.length()){
            string temp = a;
            a = b;
            b = temp;
        }
        int carry =  0 , i = a.length()-1 , j = b.length()-1;
        string res = "";
        while(i>=0 && j >= 0){
            int sum = 0;
            a.substr(i,1) == "1" ? sum+= 1 : sum+= 0;
            b.substr(j,1) == "1" ? sum+= 1 : sum+= 0;
            sum += carry;
            if(sum == 0){
                res+="0";
                carry=0;
            }
            else if (sum == 1){
                res += "1";
                carry = 0;
            }
            else if (sum == 2) {
                res+= "0";
                carry = 1;
            }
            else if (sum == 3){
                res+= "1";
                carry = 1;
            }
            --i;
            --j;
        }
            while(i>=0){
               int sum = 0;
               a.substr(i,1) == "1" ? sum+= 1 : sum+= 0;
               sum+=carry;
               if(sum == 0){
                   res += "0";
                   carry = 0;
               } 
                else if (sum == 1){
                res += "1";
                carry = 0;
                }
            else if (sum == 2) {
                res+= "0";
                carry = 1;
            }
            --i;
            }
            if(carry == 1)res+="1";  
        reverse(res.begin(),res.end());
        return res;
    }
int main()
{
    // 6
    // 3 2 6 5 0 3

    // #ifndef ONLINE_MODE
    //    freopen("input.txt" , "r", stdin);
    //    freopen("output.txt","w",stdout);
    // #endif
		string a , b;
		cin>>a>>b;
		cout<<addBinary(a,b);
    return 0;
}
