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

    // Method - 1 (Using level order traversal)
    int height1(Node* root) {
        if (root==NULL){
            return 0;
        }
        queue<Node*> q;
        int c=0;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            Node* temp=q.front();
            q.pop();
            if (temp==NULL){
                c++;
                if (!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
        }
        return c-1;
    }

    // Method - 2 (using recursion)
    int height2(Node* root){
        if (root==NULL){
            return -1;
        }
        int l=height2(root->left);
        int r=height2(root->right);
        return max(l,r)+1;
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
    cout<<s.height1(root)<<endl;
    cout<<s.height2(root)<<endl;
}