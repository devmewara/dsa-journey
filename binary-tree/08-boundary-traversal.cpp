#include<iostream>
#include<queue>
#include<vector>
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
    void leftPart(Node* root, vector<int> &ans){
        if (root==NULL){
            return ;
        }
        if (!root->left && !root->right){
            return ;
        }
        ans.push_back(root->data);
        if (root->left){
            leftPart(root->left,ans);    
        }
        else{
            leftPart(root->right,ans);    
        }
    }
    void middlePart(Node* root, vector<int> &ans){
        if (root==NULL){
            return ;
        }
        if (!root->left && !root->right){
            ans.push_back(root->data);
        }
        middlePart(root->left,ans);
        middlePart(root->right,ans);
    }
    void rightPart(Node* root, vector<int> &ans){
        if (root==NULL){
            return ;
        }
        if (!root->left && !root->right){
            return ;
        }
        if (root->right){
            rightPart(root->right,ans);    
        }
        else{
            rightPart(root->left,ans);    
        }
        ans.push_back(root->data);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        leftPart(root->left,ans);
        middlePart(root->left,ans);
        middlePart(root->right,ans);
        rightPart(root->right,ans);
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
    vector<int> ans=s.boundaryTraversal(root);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}