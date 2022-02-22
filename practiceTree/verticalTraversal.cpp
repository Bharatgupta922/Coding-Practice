#include<bits/stdc++.h>
using namespace std ;


class node {
    public :
    int data ;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        this->left=NULL;
        this->right = NULL;
    }

};
node * buildTree(node * root){
    int data ;
    cin>>data;
    if(data == -1) return NULL;
    root = new node(data);
    cout<<"insert for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"insert for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
}

void printvector(vector<int> v){
    for(auto i : v){
        cout<<i<<" , ";
    }
    cout<<endl;
}
vector<int> verticalOrderTraversal(node * root){
    vector<int> ans;
    map<int,map<int,vector<int> > > nodes;
    queue<pair<node* , pair<int,int> > > q;

    if(root == NULL)return ans;
    q.push({root , {0,0}});
    while(!q.empty()){
        pair<node*,pair<int,int> > temp = q.front();
        node * frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);
        if(frontnode->left){
            q.push({frontnode->left , {hd-1 , lvl+1}});
        }
        if(frontnode->right){
            q.push({frontnode->right , {hd+1 , lvl+1}});
        }
    }
    for(auto i : nodes)
        for(auto j : i.second)
            for(auto k : j.second)
                ans.push_back(k);
    return ans;
}
int main(){
    
    #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
    #endif
    node * root = NULL;
    root = buildTree(root);
    printvector(verticalOrderTraversal(root));
    return 0;
}