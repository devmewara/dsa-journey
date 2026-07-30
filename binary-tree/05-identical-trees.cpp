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
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        if (r1==NULL && r2==NULL){
            return 1;
        }
        if ((r1==NULL && r2!=NULL) || r1!=NULL && r2==NULL){
            return 0;
        } 
        if (r1->data != r2->data){
            return 0;
        }
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
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
    Node* root1=NULL;
    Node* root2=NULL;
    buildFromLevelOrder(root1);
    buildFromLevelOrder(root2);
    cout<<s.isIdentical(root1,root2)<<endl;
}