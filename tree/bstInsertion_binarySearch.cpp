#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
node *getNewNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
bool binarySearch(node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else if (x <= root->data)
        return binarySearch(root->left, x);
    else
        return binarySearch(root->right, x);
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 35);
    root = insert(root, 9);
    cout << "Enter number be searched " << endl;
    int number;
    cin >> number;
    if (binarySearch(root, number))
        cout << "found" << endl;
    else
        cout << "Not Found" << endl;
    inorder(root);
    return 0;
}
