#include <iostream>
#include <queue>
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
node *getnewNode(int data)
{
    node *temp = new node(data);
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
node *insert()
{
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    node *temp = getnewNode(x);
    cout << "Enter the value of left node of " << x << " or -1 for NULL" << endl;
    temp->left = insert();
    cout << "Enter the value of right node of " << x << " or -1 for NULL" << endl;
    temp->right = insert();
    return temp;
}
void getKthlevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
    {
        cout << root->data << " ";
        return;
    }
    getKthlevel(root->left, level - 1);
    getKthlevel(root->right, level - 1);
}
int main()
{
    cout << "insert the value of root element of -1 for creating empty tree " << endl;
    root = insert();
    getKthlevel(root, 2);
    return 0;
}
