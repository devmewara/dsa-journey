#include<iostream>
#include<queue>
using namespace std;

// Node creation
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

// Binary tree creation
Node* buildTree(Node* root){
    cout<<"Enter data: ";
    int data;
    cin>>data;
    root=new Node(data);
    if (data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

// Build binary tree from Level Order
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

// Level order traversal
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

// Pre-Order traversal
void preOrderTraversal(Node* root){
    if (root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// In-Order Traversal
void inOrderTraversal(Node* root){
    if (root==NULL){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

// Post-Order Traversal
void postOrderTraversal(Node* root){
    if (root==NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root1=NULL;
    // Creating tree
    root1=buildTree(root1);
    // Printing
    cout<<endl<<"Level order traversal: "<<endl;
    levelOrderTraversal(root1);
    cout<<endl<<"Pre-Order traversal: "<<endl;
    preOrderTraversal(root1);
    cout<<endl<<"In-Order traversal: "<<endl;
    inOrderTraversal(root1);
    cout<<endl<<"Post-Order traversal: "<<endl;
    postOrderTraversal(root1);

    // Creating another tree
    Node* root2=NULL;
    buildFromLevelOrder(root2);
    // Printing
    cout<<endl<<"Level order traversal: "<<endl;
    levelOrderTraversal(root2);
    cout<<endl<<"Pre-Order traversal: "<<endl;
    preOrderTraversal(root2);
    cout<<endl<<"In-Order traversal: "<<endl;
    inOrderTraversal(root2);
    cout<<endl<<"Post-Order traversal: "<<endl;
    postOrderTraversal(root2);

    return 0;
}