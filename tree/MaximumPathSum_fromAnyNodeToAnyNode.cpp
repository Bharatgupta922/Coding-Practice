#include <iostream>
#include <climits>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
node *first = NULL;
node *insert()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return NULL;
    }
    node *temp = new node(x);
    cout << "Enter the left element of node " << x << " or -1 for NULL" << endl;
    temp->left = insert();
    cout << "Enter the right element of node " << x << " or -1 for NULL" << endl;
    temp->right = insert();
    return temp;
}
int findDiameter(node *root, int &res)
{
    if (root == nullptr)
    {
        return 0;
    }

    int l = findDiameter(root->left, res);
    int r = findDiameter(root->right, res);

    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(temp, root->data + l + r);
    res = max(res, ans);

    return temp;
}
int main()
{
    cout << "insert the root element or -1 for null tree" << endl;
    first = insert();
    int res = INT_MIN;
    findDiameter(first, res);
    cout << "Diameter of the given tree is " << res << endl;

    return 0;
}