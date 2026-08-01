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


bool searchInBST(Node *root, int x) {
    if (root==NULL){
        return 0;
    }
    if (root->data==x){
        return 1;
    }
    if (root->data>x){
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
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

int main(){

    Node* root=NULL;
    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    cout<<"Enter element to search in BST: ";
    int n;
    cin>>n;
    cout<<searchInBST(root,n)<<endl;
    
}