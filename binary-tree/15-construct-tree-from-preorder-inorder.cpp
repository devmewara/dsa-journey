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
    int preorderIndex=0;
    
    Node* solve(vector<int> inorder,vector<int> preorder,int inorderStart,int inorderEnd){
        if (inorderStart>inorderEnd){
            return NULL;
        }
        int v=preorder[preorderIndex++];
        Node* root=new Node(v);
        int pos=mp[v];
        root->left=solve(inorder,preorder,inorderStart,pos-1);
        root->right=solve(inorder,preorder,pos+1,inorderEnd);
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n=inorder.size();
        for (int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder,preorder,0,n-1);
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