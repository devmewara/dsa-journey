#include<iostream>
#include<queue>
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
    int height(Node* root){
        if (root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
    
  public:
    bool isBalanced(Node* root) {
        if (root==NULL){
            return 1;
        }
        if (abs(height(root->left)-height(root->right))>1){
            return 0;
        }
        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);
        return l&&r;
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
    cout<<s.isBalanced(root)<<endl;
}