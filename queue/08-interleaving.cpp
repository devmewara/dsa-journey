#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {

        // Method - 1 (using another queue)
        /*queue<int> q1;
        queue<int> q2;
        int n=q.size();
        int i=0;
        while (i<n/2){
            q1.push(q.front());
            q.pop();
            i++;
        }
        i=0;
        while (i<n/2){
            q2.push(q.front());
            q.pop();
            i++;
        }
        while (!q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q2.front());
            q2.pop();
        }*/


        // Method - 2 (using another stack)
        int n=q.size();
        stack<int> s;
        int i=0;
        while (i<n/2){
            s.push(q.front());
            q.pop();
            i++;
        }
        while (!s.empty()){
            q.push(s.top());
            s.pop();
        }
        i=0;
        while (i<n/2){
            q.push(q.front());
            q.pop();
            i++;
        }
        i=0;
        while(i<n/2){
            s.push(q.front());
            q.pop();
            i++;
        }
        while (!s.empty()){
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};

// Print
void print(queue<int> q){
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}


// Driver Code
int main(){
    cout<<"Enter n and n elements: "<<endl;
    int n;
    cin>>n;
    queue<int> q;
    for (int i=0;i<n;i++){
        int ele;
        cin>>ele;
        q.push(ele);
    }

    Solution s;
    s.rearrangeQueue(q);
    print(q);

}