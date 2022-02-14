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
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    node *temp = new node(data);
    cout << "Enter the left child of " << data << " or -1 for NULL" << endl;
    temp->left = insert();
    cout << "Enter the right child of " << data << " or -1 for NULL" << endl;
    temp->right = insert();
    return temp;
}

bool ischildrenSum(node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->data;
    if (root->right != NULL)
        sum += root->right->data;
    if (sum == root->data && ischildrenSum(root->left) && ischildrenSum(root->right))
        return true;
    else
        return false;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    cout << "insert the root node " << endl;
    root = insert();
    inorder(root);
    if (ischildrenSum(root))
        cout << endl
             << "true";
    else
        cout << endl
             << "false";
    return 0;
}
