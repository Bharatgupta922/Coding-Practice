#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool check(vector<int> vec, int product)
{
    unordered_set<int> us;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if ((product % (*it) == 0) and (us.find(product / (*it)) != us.end()))
        {
            cout << *it << " " << product / (*it) << endl;
            return true;
        }
        else
        {
            us.insert(*it);
        }
    }
    return false;
}
int main()
{
    cout << "Enter the test cases" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        cout << "Enter the number of elements" << endl;
        int n, element, product;
        cin >> n;
        vector<int> vec;
        cout << "Enter the Elements" << endl;
        while (n--)
        {
            cin >> element;
            vec.push_back(element);
        }
        cout << "enter the product" << endl;
        cin >> product;
        check(vec, product) ? cout << "present" << endl : cout << "Not present" << endl;
    }
    return 0;
}