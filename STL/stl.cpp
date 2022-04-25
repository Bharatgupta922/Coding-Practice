#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <climits>
using namespace std;
bool compare(int x, int y)
{
    return x > y;
}
void vectorDemo()
{
    vector<int> A = {11, 2, 3, 14};
    cout << A[0] << endl;
    sort(A.begin(), A.end()); //O(nlogn)
    //2,3,11,14
    bool present = binary_search(A.begin(), A.end(), 4); //O(logn)
    if (present)
        cout << "present" << endl; //false
    else
        cout << "not present" << endl;
    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100); //true
    if (present)
        cout << "present" << endl;
    else
        cout << "not present" << endl;
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100); //O(1)
    A.push_back(123);
    //11,2,3,14,100,100,100,100,100,100,123

    //here upperbound means element which is strictly greater than the argument
    //and lowerbound means element which is less then or equal to the argument
    vector<int>::iterator it1 = lower_bound(A.begin(), A.end(), 100); //>=    O(logn)
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); //>
                                                                      //        auto it1 = lower_bound(A.begin(),A.end(),100);//>=
                                                                      //  auto it2 = upper_bound(A.begin(),A.end(),100);//>
                                                                      //auto can also be used
    cout << *it1 << endl;
    cout << *it2 << endl;
    cout << it2 - it1 << endl;   //6
    cout << *it2 - *it1 << endl; //123-100
    sort(A.begin(), A.end(), compare);
    for (vector<int>::iterator it3 = A.begin(); it3 != A.end(); it3++)
        cout << *it3 << " ";
    cout << endl;
    // for(int x : A){
    //     cout<<
    // }
    //it can be used to print the vector
    // for(int &x : A){
    //     x++;
    // }
    //if you want to update also in the elements of vector without using an iterator
    // for(int x : A){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    //you can iterate also like that
    //without using an iterator
}
void setDemo()
{
    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(3);
    S.insert(-1);
    S.insert(-11);
    S.insert(-10);
    S.insert(0);
    //set insert the values in ascending order in O(logn)time
    //so you need not to use sort function explicitely like we are doing in vectors which is O(nlogn)
    for (int x : S)
        cout << x << " ";
    cout << endl;
    //-11,-10,-1,0,1,2,3
    auto it1 = S.find(-1);
    if (it1 == S.end())
    {
        cout << "not present " << endl;
    }
    else
    {
        cout << "present ";
        cout << *it1 << endl;
    }

    //here upperbound means element which is strictly greater than the argument
    //and lowerbound means element which is less then or equal to the argument
    auto it2 = S.lower_bound(-1);
    auto it3 = S.upper_bound(0);
    //here the set class has already defined functions in it to get
    //upper_bound & lower_bound so we have to use functions like find ,insert ,upper_bound or lower_bound
    // as S.find(),S.insert(),S.upper_bound(),S.lower_bound(),etc.
    cout << *it2 << "  " << *it3 << endl;
    auto it4 = S.upper_bound(3);
    if (it4 == S.end())
    {
        cout << "opps ! we do not have something like that " << endl;
    }
    else
    {
        cout << "present" << endl;
        cout << *it4 << endl;
    }
    S.erase(-1);
    for (int x : S)
        cout << x << " ";
    cout << endl;
    S.insert(-1);
    for (int x : S)
        cout << x << " ";
    cout << endl;
    S.erase(it3, S.end());
    for (int x : S)
        cout << x << " ";
    cout << endl;
}
void mapDemo()
{
    map<int, int> A;
    A[1] = 1;
    A[2] = -1;
    A[3] = 200;
    A[10000232] = 1;

    map<char, int> cnt;
    string x = "bharat gupta";
    for (char c : x)
    {
        cnt[c]++;
    }
    cout << cnt['a'] << " " << cnt['t'] << " " << endl;
}
void powerOfstl()
{
    // //[x,y]
    // add[2,3]
    // add[10,20]
    // add[30,400]
    // add[401,450]
    // so the pairs are not overlapping
    // now let say that i/p is 13
    // then o/p is [10,20]
    // like for i/p  400 the o/p is [30,400]
    set<pair<int, int>> S;

    S.insert({501, 670});
    S.insert({30, 200});
    S.insert({400, 500});
    S.insert({10, 20});
    S.insert({2, 3});

    //as all know that insertion in set is always be in sorted order
    // question is that how be a pair is small or large
    // let {a,b} is smaller than {c,d} iff (a<c) or (a==c and b<d);

    int point = 50;
    auto it = S.upper_bound({point, INT_MAX});
    it--;
    pair<int, int> current = *it;
    if (current.first <= point && current.second >= point)
        cout << "the point " << point << " is present in pair"
             << " {" << current.first << " , " << current.second << "}" << endl;
    else
        cout << "the point " << point << " is not present in pair"
             << " {" << current.first << " , " << current.second << "}" << endl;
}
int main()
{
    ///c++
    
    return 0;
}
