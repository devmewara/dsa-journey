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


void solve(Node* root,int &count){
    if (root==NULL){
        return ;
    }
    solve(root->left,count);
    if (root->left==NULL && root->right==NULL){
        count++;
    }
    solve(root->right,count);
}

int noOfLeafNodes(Node *root){
    int count=0;
    solve(root,count);
    return count;
}


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
    Node* root=NULL;
    buildFromLevelOrder(root);
    cout<<noOfLeafNodes(root)<<endl;
}