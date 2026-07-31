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
    vector<int> topView(Node *root) {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while (!q.empty()){
            Node* temp=q.front().first;
            int col=q.front().second;
            q.pop();
            if (mp.find(col)==mp.end()){
                mp[col]=temp->data;
            }
            if (temp->left){
                q.push({temp->left,col-1});
            }
            if (temp->right){
                q.push({temp->right,col+1});
            }
        }
        vector<int> ans;
        for (auto i : mp){
            ans.push_back(i.second);
        }
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
    vector<int> ans=s.topView(root);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}