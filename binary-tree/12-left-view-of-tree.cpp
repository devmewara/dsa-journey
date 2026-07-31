#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
    
    // Method -1 (using level order traversal)
    vector<int> leftView1(Node *root) {
        vector<int> ans;
        if (root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int n=q.size();
            ans.push_back(q.front()->data);
            while (n--){
                Node* temp=q.front();
                q.pop();
                if (temp->left){
                    q.push(temp->left);
                }
                if (temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }

    // Method - 2 (using recursion)
    void solve(Node* root, vector<int> &ans,int level){
        if (root==NULL){
            return ;
        }
        if (level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }

    vector<int> leftView2(Node* root){
        int level=0;
        vector<int> ans;
        solve(root,ans,level);
        return ans;
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
    vector<int> ans1=s.leftView1(root);
    for (int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    vector<int> ans2=s.leftView2(root);
    for (int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
}