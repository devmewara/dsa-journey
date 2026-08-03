#include<iostream>
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


Node* LCAinaBST(Node* root, Node* P, Node* Q) {
    if (root == NULL) {
        return NULL;
    }
    if (P->data < root->data && Q->data < root->data) {
        return LCAinaBST(root->left, P, Q);
    }
    if (P->data > root->data && Q->data > root->data) {
        return LCAinaBST(root->right, P, Q);
    }
    return root;
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

Node* searchBST(Node* root, int key) {

    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

int main(){

    Node* root=NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    cout<<"Enter two elements: ";
    int p,q;
    cin>>p>>q;
    Node* P=searchBST(root,p);
    Node* Q=searchBST(root,q);
    cout<<LCAinaBST(root,P,Q)->data<<endl;
    
}