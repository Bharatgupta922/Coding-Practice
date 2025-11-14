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
void inorder(node * root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" , ";
        inorder(root->right);
    }
}
void postorder(node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" , ";
    }
}
void preorder(node * root){
    if(root!=NULL){
        cout<<root->data<<" , ";
        preorder(root->left);
        preorder(root->right);
    }
}
void levelOrderTraversal(node * root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
        
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
        cout<<temp->data<<" ";
        if(temp->left !=NULL)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        }
    }
}
void buildTreeUsingLevelOrder(node* &root){
    queue<node * > q;
    int data ;
    cin>>data;
    if(data == -1){
        root = NULL;
        return;
    }
    root = new node(data);
        
        q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        int leftnode;
        int rightnode;
        cout<<"enter left of "<<temp->data<<endl;
        cin>>leftnode;
        cout<<"endter right of "<<temp->data<<endl;
        cin>>rightnode;
        if(leftnode != -1){
            temp->left = new node(leftnode);
            q.push(temp->left);
        }
        if(rightnode != -1){
            temp->right = new node(rightnode);
            q.push(temp->right);
        }
    }
}
int height(node * root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
}
pair<int,int> diameterFastUtil(node * root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterFastUtil(root->left);
    pair<int,int> right = diameterFastUtil(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + 1 + right.second ;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second , right.second) + 1;
    return ans;
}
int diameterFast(node * root){
return diameterFastUtil(root).first;
}
int diameter(node * root){
    if(root == NULL)return 0;
        int op1 = diameter(root->right);
        int op2 = height(root->left) + 1 + height(root->right);
        int op3 = diameter(root->left);
        return max(op1 , max(op2,op3));
}

bool isBalanced(node* root){
    if(root == NULL)return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff)
    return true;
    else return false;
}

pair<bool , int> isBalancedFastUtil(node * root){
    if(root == NULL){
        pair<bool , int> p = make_pair(true , 0);
        return p;
    }

    pair<bool , int> left = isBalancedFastUtil(root->left);
    pair<bool , int> right = isBalancedFastUtil(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second , right.second) + 1 ;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else {
        ans.first = false;
    }
    return ans;
}
bool isBalancedFast(node * root){
    return isBalancedFastUtil(root).first;
}
bool isIdentical(node * root1 , node * root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
        return false ;
    }
    bool left = isIdentical(root1->left , root2->left);
    bool right = isIdentical(root1->right , root2->right);
    bool value = root1->data == root2->data;
    if(left && right && value)
    return true;
    else return false;

}
pair<bool , int> isSumTreeUtil(node * root){
    if(root == NULL){
        return make_pair(true,0);
    }
    if(root -> left == NULL && root->right == NULL){
        return make_pair(true ,  root->data);
    }

    pair<bool , int> left = isSumTreeUtil(root->left);
    pair<bool , int> right = isSumTreeUtil(root->right);
    
    bool current = root->data  == left.second + right.second;

    pair<bool , int> ans;
    ans.second = root->data + left.second + right.second;
    if(left.first && right.first && current){
         ans.first = true;
    }
    else {
         ans.first = false;
    }
    return ans;
}
bool isSumTree(node* root){
    return isSumTreeUtil(root).first;
    
}

vector<int> zigzagTraversal(node* root){
    vector<int> ans;
    if(root == NULL)return ans;

        bool flag  = true;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0 ;  i < size ; ++i){
            node * frontnode = q.front();
            q.pop();
            int index = flag?i:size-i-1;
            // int index = i;      // this is the 
            temp[index] = frontnode->data;
            if(frontnode->left)q.push(frontnode->left);
            if(frontnode->right)q.push(frontnode->right);
        }
        flag = !flag;
        for(auto i : temp){
            ans.push_back(i);
        }
    }
    return ans;
}
void traverseLeft(node * root , vector<int> &ans){
    if(root == NULL)return ;
    if(root->left == NULL && root->right == NULL)return ;
    ans.push_back(root->data);
    if(root->left)
     traverseLeft(root->left,ans);
    else  traverseLeft(root->right,ans);

}
void traverseleaf(node * root , vector<int> &ans){
    if(root==NULL)return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return ;
    }
    traverseleaf(root->left , ans);
    traverseleaf(root->right , ans);
}
void traverseRight(node * root , vector<int> &ans){
    if(root == NULL)return ;
    if(root->left == NULL && root->right == NULL)return ;
    if(root->right)traverseRight(root->right , ans);
    else traverseRight(root->left , ans);
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(node * root){
    vector<int> ans;
    if(root == NULL)
    return ans;
    ans.push_back(root->data);
    traverseLeft(root->left , ans);
    traverseleaf(root , ans);
    traverseRight(root->right , ans);
    return ans;
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
        q.pop();
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


vector<int> topView(node * root){
    vector<int> ans;
    if(root == NULL)return ans;
    map<int,int> topNode;
    queue<pair<node*,int>  > q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node * frontNode = temp.first;
        int hd = temp.second;
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left)q.push(make_pair(frontNode->left , hd-1));
        if(frontNode->right)q.push(make_pair(frontNode->right,hd+1));
    }
    for(auto i : topNode){
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottomView(node* root){
vector<int> ans;
if(root == NULL)return ans;
map<int,int> bottomNode;
queue<pair<node* , int> > q;
q.push(make_pair(root,0));
while(!q.empty()){
    pair<node*,int> temp = q.front();
    q.pop();
    node * frontNode = temp.first;
    int hd = temp.second;
    bottomNode[hd] = frontNode->data;
    if(frontNode->left)q.push(make_pair(frontNode->left,hd-1));
    if(frontNode->right)q.push(make_pair(frontNode->right,hd+1));
}
for(auto i : bottomNode){
    ans.push_back(i.second);
}
return ans;
}
void leftViewUtil(node* root ,vector<int>  &ans,int lvl){
if(root == NULL)return ;
if(lvl == ans.size())
ans.push_back(root->data);
leftViewUtil(root->left,ans,lvl+1);
leftViewUtil(root->right,ans,lvl+1);
}
vector<int> leftView(node * root){
    vector<int> v;
    if(root == NULL)return v;
    leftViewUtil(root , v,0);
    return v;
}

void rightViewUtil(node* root ,vector<int>  &ans,int lvl){
if(root == NULL)return ;
if(lvl == ans.size())
ans.push_back(root->data);
leftViewUtil(root->right,ans,lvl+1);
leftViewUtil(root->left,ans,lvl+1);
}
vector<int> rightView(node * root){
    vector<int> v;
    if(root == NULL)return v;
    rightViewUtil(root , v,0);
    return v;
}
vector<int> diagonalView(node * root){
    vector<int> ans;
    if(root == NULL)return ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node * frontNode = q.front();
        q.pop();
        while(frontNode){
            ans.push_back(frontNode->data);
            if(frontNode->left)q.push(frontNode->left);
            frontNode=frontNode->right;
        }
    }
    return ans;
}
int main(){

    #ifndef ONLINE_MODE
       freopen("input.txt" , "r", stdin);
       freopen("output.txt","w",stdout); 
    #endif
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node * root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"height is "<<height(root)<<endl;
    cout<<"diameter or width "<<diameter(root)<<endl;
    cout<<"diameter or width fast "<<diameterFast(root)<<endl;
    isBalanced(root)?cout<<"Balanced"<<endl:cout<<"not balanced"<<endl;
    isBalancedFast(root)?cout<<"Balanced Fast"<<endl:cout<<"not balanced Fast"<<endl;
    isSumTree(root)?cout<<"Sum tree"<<endl:cout<<"not a sum tree"<<endl;
    printvector(zigzagTraversal(root));
    printvector(boundaryTraversal(root));
    printvector(verticalOrderTraversal(root));
    printvector(topView(root));
    printvector(bottomView(root));
    printvector(leftView(root));
    printvector(rightView(root));
    printvector(diagonalView(root));

    return 0;
}