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


// Method - 1 (using inorder)
void inOrder(Node *root,vector<int> &v){
    if (root==NULL){
        return ;
    }
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

bool validateBST1(Node *root) {
    vector<int> v;
    inOrder(root,v);
    for (int i=1;i<v.size();i++){
        if (v[i]<=v[i-1]){
            return 0;
        }
    }
    return 1;
}


// Method - 2 (usign min and max value)
bool solve(Node *root,int mini,int maxi){
    if (root==NULL){
        return 1;
    }
    if (root->data>mini && root->data<maxi){
        bool left=solve(root->left,mini,root->data);
        bool right=solve(root->right,root->data,maxi);
        return left && right;
    }
    else{
        return 0;
    }
}
bool validateBST2(Node *root) {
    return solve(root,INT_MIN,INT_MAX);
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

    cout<<validateBST1(root)<<endl;
    cout<<validateBST2(root)<<endl;
    
}