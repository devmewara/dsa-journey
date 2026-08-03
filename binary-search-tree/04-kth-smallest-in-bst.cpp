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


void solve(Node* root,int &c,int k,int &ans){
    if (root==NULL || ans!=-1){
        return ;
    }
    solve(root->left,c,k,ans);
    c++;
    if (c==k){
        ans=root->data;
    }
    solve(root->right,c,k,ans);
}
int kthSmallest(Node* root, int k) {
    int ans=-1;
    int c=0;
    solve(root,c,k,ans);
    return ans;
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
    cout<<"Enter k: ";
    int k;
    cin>>k;
    cout<<kthSmallest(root,k)<<endl;
    
}