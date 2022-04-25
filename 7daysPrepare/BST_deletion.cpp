// smaple inpput
// 14
// 9 5 4 8 7 2 0 15 13 19 10 14 18 21
// smaple output 
// 0 , 2 , 4 , 5 , 7 , 8 , 9 , 10 , 13 , 14 , 15 , 18 , 19 , 21 , 
// 0 , 2 , 4 , 5 , 7 , 8 , 9 , 10 , 13 , 14 , 18 , 19 , 21 , 

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
void insertdata(node * &root , int data){
    if(root == NULL){
        root = new node(data);
    }
    else{
        if(data <= root->data){
            insertdata(root->left,data);
        }
        else {
            insertdata(root->right,data);
        }
    } 
}
node * solve(int * a, int n){
    node * root = new node(a[0]);
for(int i = 1 ;  i < n  ; ++i)
{
    insertdata(root,a[i]);
}
return root;
}
void inorder(node * root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" , ";
        inorder(root->right);
    }
}
node * minValue(node * root){
    if(root->left == NULL)return root;
    return minValue(root->left);
}
node * deleteTheValue(node * root , int d){
    if(root == NULL)return NULL;
    if(root->data == d){
        //0 child 
        if(root->left == NULL && root->right == NULL){
            delete root ;
            return NULL;
        }
        //1 left child
        if(root->left != NULL && root->right == NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        
        //1 right child 
        if(root->right != NULL && root->left == NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }

        //2 child 
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            deleteTheValue(root->right , mini);
            return root;
        }
    }
    else if(root->data > d){
        root->left = deleteTheValue(root->left,d);
        return root;
    }
    else {
        root->right = deleteTheValue(root->right,d);
        return root;
    }
}
int main(){

 #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
#endif

int n;
cin>>n;
int a[n];
for(int i=0;i<n; ++i){
    cin>>a[i];
}
node * root ;
root = solve(a,n);
inorder(root);
root = deleteTheValue(root , 15);
cout<<endl;
inorder(root);
    return 0;

}