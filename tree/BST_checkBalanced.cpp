#include <iostream>
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
node *root = NULL;
node *insert()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    node *temp = new node(x);
    cout << "Enter the left element of " << x << " or -1 for NULL" << endl;
    temp->left = insert();
    cout << "Enter the right element of " << x << " or -1 for NULL" << endl;
    temp->right = insert();
    return temp;
}
bool isbalanced(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    int leftHeight = 0, rightHeight = 0;
    bool leftTree = isbalanced(root->left, &leftHeight);
    bool rightTree = isbalanced(root->right, &rightHeight);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    *height = max(leftHeight, rightHeight) + 1;
    return leftTree && rightTree;
}
int main()
{
    cout << "insert the root element" << endl;
    root = insert();
    int height = 0;
    if (isbalanced(root, &height))
        cout << "balanced with height " << height << endl;
    else
        cout << "unbalanced with height " << height << endl;

    return 0;
}
