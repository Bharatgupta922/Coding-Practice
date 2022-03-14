#include<bits/stdc++.h>
using namespace std;
bool solve(string s){
    stack<char> st;
    for(int i = 0 ;  i < s.size() ; ++i){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
            st.push(ch);
        }
        else {
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top()!= '('){
                    char x = st.top();
                    if( x == '+' || x == '-' || x == '/' || x == '*'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true)return true;
                st.pop();
            }
        }
    }
    return false;

}
int main(){
    string s =  "((b+c))";
    solve(s)?cout<<"Yes":cout<<"No";


    return 0;
}