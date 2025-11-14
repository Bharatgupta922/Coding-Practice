#include<bits/stdc++.h>
using namespace std;
void print(vector<int> ans) {
    cout<<"startPrinting";
        for (auto x: ans) cout<<x<<"------"<<endl;
        cout<<ans.size();
    cout<<"endPrinting";
}
int myAtoi(string s) {
        vector<int> ans;
        bool isNegative = false;
        for (char x : s) 
        if (x != ' ' && x != '-' && x != '+' && !(x >= '0' && x <= '9')) {
            // cout<<"step1"<<endl;
            break;
        }
        else if (x == '-') {
            // cout<<"step2"<<endl;
            isNegative = true;
        }
        else if (x >= '0' && x <= '9') {
            // cout<<"step3"<<endl;
            ans.push_back(x-'0');
        }
            // print(ans);
        int res = 0, dec = 10;
        bool mxOut = false;
        for (int i = 0; i < ans.size(); ++i)
        if (res > (INT_MAX - ans[i])/10) {
            mxOut = true;
            break;
        } else res = (res*dec) + ans[i];
        if (mxOut) return isNegative ? INT_MIN : INT_MAX;
        if (isNegative) res = -res;
        return res;
    }

int main() {
    string s;
    cin>>s;
    cout<<myAtoi(s);
    return 0;
}