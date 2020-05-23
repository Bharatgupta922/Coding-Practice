#include <iostream>
#include <climits>
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
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// int findmin(struct node * root){
//     if(root == NULL){
//         cout<<"Error : tree is empty ";
//         return -1;
//     }
//     while(root->left != NULL)root = root->left;
//     return root->data;
// }
// int findmax(struct node * root){
//     if(root == NULL){
//         cout<<"Error : tree is empty ";
//         return -1;
//     }
//     while(root->right != NULL)root = root->right;
//     return root->data;
// }
int findmin(struct node *root)
{
    if (root == NULL)
    {
        cout << "Error : tree is empty";
        return -1;
    }
    if (root->left == NULL)
        return root->data;
    return findmin(root->left);
}
int findmax(struct node *root)
{
    if (root == NULL)
    {
        cout << "Error : tree is empty ";
        return -1;
    }
    if (root->right == NULL)
        return root->data;
    return findmax(root->right);
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
    inorder(root);
    cout << endl
         << "minimum in the tree " << findmin(root) << endl;
    cout << "maximum in the tree " << findmax(root) << endl;

    return 0;
}
