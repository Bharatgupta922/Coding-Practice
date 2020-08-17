#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int check_nth_bit(int num, int place) {
    return num & (1<<(place-1));
}
int getlastSetbitPosition(int m) {
    if (m < 0)return 0;
    return (int)log2(m & -m) + 1;
}
void solve(vector<int> vec, int n) {

    int m = 0;
    for (auto x : vec)
        m^=x;
    for (int i = 1; i <= n; ++i)
        m^=i;
    int right_set_bit = getlastSetbitPosition(m);
    int xor1 = 0, xor2  = 0;
    for (int i = 0; i < n; ++i)
        if (check_nth_bit(vec[i], right_set_bit))
            xor1^=vec[i];
        else
            xor2^=vec[i];
    for (int i = 1; i <= n; ++i)
        if (check_nth_bit(i, right_set_bit))
            xor1^=i;
        else
            xor2^=i;
    cout<<xor1<<" "<<xor2<<endl;
}
int main() {
    int n;
    cin>>n;
    vector<int> vec(n, 0);
    for (int i =0; i < n; ++i)cin>>vec[i];
    solve(vec, n);

    return 0;
}