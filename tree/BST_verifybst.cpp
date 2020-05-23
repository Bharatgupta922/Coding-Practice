#include <iostream>
#include <climits>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
struct node *root = NULL;
struct node *create()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    node *temp = new node();
    temp->data = x;
    cout << "Enter the data of left child of " << x << " or -1 for nothing " << endl;
    temp->left = create();
    cout << "Enter the data of right child of " << x << " or -1 for nothing " << endl;
    temp->right = create();
    return temp;
}
// bool isSubtreeIsLesser(node * root,int value){
//     if(root == NULL)return true;
//     if(root->data <= value
//     && isSubtreeIsLesser(root->left,value)
//     && isSubtreeIsLesser(root->right,value))
//     return true;
//     else return false ;
// }
// bool isSubtreeIsGreater(node * root , int value){
// if(root == NULL)return true;
//     if(root->data > value
//     && isSubtreeIsGreater(root->left,value)
//     && isSubtreeIsGreater(root->right,value))
//     return true;
//     else return false ;
// }
// bool isBst(node * root){
//     if(root == NULL)return true;
//     if(isSubtreeIsLesser(root->left,root->data)
//     &&isSubtreeIsGreater(root->right,root->data)
//     &&isBst(root->left)
//     &&isBst(root->right))
//     return true;
//     else return false ;
// }

/// or this approach
bool isbtAbst(node *root, int min, int max)
{
    if (root == NULL)
        return true;
    return root->data >= min && isbtAbst(root->left, min, root->data) && root->data < max && isbtAbst(root->right, root->data, max);
}

// upper function can be written like this also

// bool isbtAbst(node * root , int min , int max){
//     if(root == NULL)return true;
//     if( root->data >= min && isbtAbst(root->left , min , root->data)
//     && root->data < max && isbtAbst(root->right , root->data , max))
//     return true;
//     else return false ;

// }
bool isbinaryBst(node *root)
{
    return isbtAbst(root, INT_MIN, INT_MAX);
}
int main()
{
    cout << "Enter the data of root node" << endl;
    root = create();
    if (isbinaryBst(root))
        cout << "it is a BST" << endl;
    else
        cout << "it is not a BST" << endl;
    return 0;
}
