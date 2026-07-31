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
    
    void solve(Node* root, vector<int> &ans,int level){
        if (root==NULL){
            return ;
        }
        if (level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }

    vector<int> rightView(Node* root){
        int level=0;
        vector<int> ans;
        solve(root,ans,level);
        return ans;
    }
};



// Driver code

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while (!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if (leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if (rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}


int main(){
    Solution s;
    Node* root=NULL;
    buildFromLevelOrder(root);
    vector<int> ans=s.rightView(root);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}