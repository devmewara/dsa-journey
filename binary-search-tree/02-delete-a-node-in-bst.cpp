#include<iostream>
#include <queue>
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


Node* minVal(Node* root){
    if (root==NULL){
        return root;
    }
    Node* temp=root;
    while (temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* deleteFromBST(Node* root,int x){
    if (root==NULL){
        return root;
    }
    if (root->data==x){

        // Have 0 child
        if (root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // Have 1 child (left child)
        if (root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // Have 1 child (right child)
        if (root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //Have 2 child
        if (root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    }
    else if (root->data>x){
        root->left= deleteFromBST(root->left,x);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,x);
        return root;
    }
}


// Driver code

Node* insertIntoBST(Node* root,int data){
    if (root==NULL){
        root=new Node(data);
        return root;
    }
    if (data> root->data){
        root->right=insertIntoBST(root->right,data);
    }
    else{
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while (data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
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

    Node* root=NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    cout<<"Enter element to delete from BST: ";
    int n;
    cin>>n;
    root=deleteFromBST(root,n);
    levelOrderTraversal(root);
    
}