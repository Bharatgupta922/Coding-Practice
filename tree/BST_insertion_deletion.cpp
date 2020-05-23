#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};
node *getnewnode(int data)
{
    node *temp = new node(data);
    temp->left = temp->right = NULL;
    return temp;
}
node *create(node *root, int data)
{
    if (root == NULL)
        return getnewnode(data);
    else if (data <= root->data)
        root->left = create(root->left, data);
    else
        root->right = create(root->right, data);
    return root;
}
node *insert(node *root, int x)
{
    node *newnode = getnewnode(x);
    if (root == NULL)
        return newnode;
    if (x < root->data)
        root->left = insert(root->left, x);
    if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node *minValueNode(node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}
node *deleteNode(node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // case 1 : has Zero child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2 : has one child
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3 : two child
        else
        {
            node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    cout << "enter number of nodes you want in BST" << endl;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        root = create(root, data);
    }
    inorder(root);
    cout << endl
         << "add one more value to insert in tree" << endl;
    cin >> data;
    root = insert(root, data);
    inorder(root);
    cout << "Enter the value that you want to delete" << endl;
    cin >> data;
    root = deleteNode(root, data);
    cout << endl;
    inorder(root);
    return 0;
}
