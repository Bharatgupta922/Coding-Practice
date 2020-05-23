#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
//dynamic memory allocation
node *getNewNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
//insertion in tree
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
// we can use this also in binary tree
void levelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount--)
        {
            cout << q.front()->data << " ";
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        cout << endl;
    }
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
    levelOrder(root);
    return 0;
}
