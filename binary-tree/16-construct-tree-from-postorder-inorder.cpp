#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

class Solution {
  public:
    map<int,int> mp;
    
    Node* solve(vector<int> inorder,vector<int> postorder,int inorderStart,int inorderEnd,int &postIndex){
        if (inorderStart>inorderEnd || postIndex<0){
            return NULL;
        }
        int v=postorder[postIndex--];
        Node* root=new Node(v);
        int pos=mp[v];
        root->right=solve(inorder,postorder,pos+1,inorderEnd,postIndex);
        root->left=solve(inorder,postorder,inorderStart,pos-1,postIndex);
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n=postorder.size();
        int postIndex=n-1;
        for (int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,n-1,postIndex);
    }
};


// Driver code

void print(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if (temp==NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}


int main(){
    Solution s;
    vector<int> inorder;
    vector<int> preorder;
    cout<<"Enter n, n elemets of inorder and n elements of preorder: "<<endl;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int val;
        cin>>val;
        inorder.push_back(val);
    }
    for (int i=0;i<n;i++){
        int val;
        cin>>val;
        preorder.push_back(val);
    }
    Node* root=s.buildTree(inorder,preorder);
    print(root);
}