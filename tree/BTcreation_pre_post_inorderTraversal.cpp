#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};
struct node *create()
{
    node *temp = new node();
    cout << "note : enter the data or enter -1 for null" << endl;
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    temp->data = x;
    cout << "enter left child of " << x << " " << endl;
    temp->left = create();
    cout << "enter right child of " << x << " " << endl;
    temp->right = create();
    return temp;
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    struct node *root = NULL;
    root = create();
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
