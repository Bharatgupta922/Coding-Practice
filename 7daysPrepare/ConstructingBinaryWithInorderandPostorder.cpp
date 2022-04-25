#include<bits/stdc++.h>
using namespace std;

class node{
public :
    int data;
    node * left ;
    node* right;
    node(int x){
    this->data = x;
    this->left = NULL;
    this->right = NULL;
}
};
void inorder(node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" , ";
        inorder(root->right);
    }
}

void postOrder(node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" , ";
    }
}
int findPosition(int in[],int element , int n ){
    for(int i = 0 ; i < n ; ++i)
        if(in[i] == element)
        return i;
        return -1;
}
node * solve(int in[],int pre[] , int &index , int inorderStart,int inorderEnd , int n){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }
    int element = pre[index++];
    node * root = new node(element);
    int position = findPosition(in,element,n);
    root->left = solve(in,pre,index,inorderStart,position-1,n);
    root->right = solve(in,pre,index,position+1,inorderEnd,n);
    return root;
}
node * ConstructTree(int in[],int pre[] , int n ){
    int preOrderIndex = 0;
    return solve(in,pre,preOrderIndex,0,n-1,n);
}

int main(){
    
 #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
#endif

int n;
cin>>n;
int in[n];
int pre[n];
for(int i = 0 ;  i < n ;++i)cin>>in[i];
for(int i =  0  ;  i< n ; ++i)cin>>pre[i];
node * root = ConstructTree(in,pre,n);
postOrder(root);
    return 0;

}
