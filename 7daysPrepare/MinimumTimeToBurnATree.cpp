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
node * createParentMapping(node * root , int target , map<node * , node*> &nodeToParent){
    node * result=NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty()){
        node * temp = q.front();
        if(temp->data == target){
            result = temp;
        }
        if(temp->left){
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            nodeToParent[temp->right] = temp;
        }
    }
    return result;
}
int burnTree(node * root , map<node * , node*> &nodeToParent){
    map<node*,bool> vis;
    queue<node*> q;
    q.push(root);
    vis[root] = true;
    int ans = 0 ;
    while(!q.empty()){
        int sz = q.size();
        bool flag = false;
        for(int i = 0 ;  i< sz ; ++i){
            node * temp = q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                flag = true;
                q.push(temp->left);
                vis[temp->left] = true;
            }
            if(temp->right && !vis[temp->right]){
                flag = true;
                q.push(temp->right);
                vis[temp->right]= true;
            }
            if(nodeToParent[temp] && !vis[nodeToParent[temp]]){
                flag = true;
                q.push(nodeToParent[temp]);
                vis[nodeToParent[temp]] = true;
            }
        }
        if(flag)ans++;
    }
    return ans;
}
void solve(node * root ,int target){
map<node * , node *> nodeToParent;
int ans = 0  ;
 node * targetNode = createParentMapping(root , target , nodeToParent);

}
int main(){
    
 #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
#endif



    return 0;

}


//   Node * createParentMapping(Node * root , int target , map<Node * , Node*> &nodeToParent){
//     Node * result=NULL;
//     queue<Node*> q;
//     q.push(root);
//     nodeToParent[root] = NULL;
//     while(!q.empty()){
//         Node * temp = q.front();
//         if(temp->data == target){
//             result = temp;
//         }
//         if(temp->left){
//             nodeToParent[temp->left] = temp;
//             q.push(temp->left);
//         }
//         if(temp->right){
//             nodeToParent[temp->right] = temp;
//             q.push(temp->right);
//         }
//     }
//     return result;
// }
// int burnTree(Node * root , map<Node * , Node*> &nodeToParent){
//     map<Node*,bool> vis;
//     queue<Node*> q;
//     q.push(root);
//     vis[root] = true;
//     int ans = 0 ;
//     while(!q.empty()){
//         int sz = q.size();
//         bool flag = false;
//         for(int i = 0 ;  i< sz ; ++i){
//             Node * temp = q.front();
//             q.pop();
//             if(temp->left && !vis[temp->left]){
//                 flag = true;
//                 q.push(temp->left);
//                 vis[temp->left] = true;
//             }
//             if(temp->right && !vis[temp->right]){
//                 flag = true;
//                 q.push(temp->right);
//                 vis[temp->right]= true;
//             }
//             if(nodeToParent[temp] && !vis[nodeToParent[temp]]){
//                 flag = true;
//                 q.push(nodeToParent[temp]);
//                 vis[nodeToParent[temp]] = true;
//             }
//         }
//         if(flag)ans++;
//     }
//     return ans;
// }
//     int minTime(Node* root, int target) 
//     {
//         //step 1 : create parent mapping
//         //step 2 : find target
//         //step 3 : burn the tree in min time 
//         int ans = 0  ;
//         map<Node*,Node*> nodeToParent;
//             Node * targetNode = createParentMapping(root , target , nodeToParent);
//          return  burnTree(targetNode,nodeToParent);
//     }