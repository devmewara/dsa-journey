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


// Method - 1 (using recursion)
Node* LCAinaBST1(Node* root, Node* P, Node* Q) {
    if (root == NULL) {
        return NULL;
    }
    if (P->data < root->data && Q->data < root->data) {
        return LCAinaBST1(root->left, P, Q);
    }
    if (P->data > root->data && Q->data > root->data) {
        return LCAinaBST1(root->right, P, Q);
    }
    return root;
}

// Method - 2 (without recusion)
Node* LCAinaBST2(Node* root,Node* P,Node* Q){
    while (root!=NULL){
        if (P->data < root->data && Q->data < root->data){
            root=root->left;
        }
        else if (P->data > root->data && Q->data > root->data){
            root=root->right;
        }
        else{
            return root;
        }
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
    cout<<LCAinaBST1(root,P,Q)->data<<endl;
    cout<<LCAinaBST2(root,P,Q)->data<<endl;
    
}