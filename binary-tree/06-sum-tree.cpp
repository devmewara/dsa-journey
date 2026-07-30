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
    int total(Node* node){
        if (node==NULL){
            return 0;
        }
        return node->data+total(node->left)+total(node->right);
    }
  public:
    bool isSumTree(Node* node) {
        if (node==NULL){
            return 1;
        }
        if (node->left==NULL && node->right==NULL){
            return 1;
        }
        if (node->data!=(total(node->left)+total(node->right))){
            return 0;
        }
        return isSumTree(node->left) && isSumTree(node->right);
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
    cout<<s.isSumTree(root)<<endl;
}