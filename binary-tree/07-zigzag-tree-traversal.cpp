#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root==NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root);
        bool leftToRight=1;
        while (!q.empty()){
            int n=q.size();
            vector<int> v(n);
            for (int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                if (leftToRight){
                    v[i]=temp->data;
                }
                else{
                    v[n-i-1]=temp->data;
                }
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
            for (int i=0;i<n;i++){
                result.push_back(v[i]);
            }
            leftToRight=!(leftToRight);
        }
        return result;
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
    vector<int> ans=s.zigZagTraversal(root);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}