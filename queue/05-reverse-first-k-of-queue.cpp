#include<iostream>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    if (q.size()<k){
        return q;
    }
    stack<int> s;
    for (int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int n=q.size()-k;
    while (n--){
        q.push(q.front());
        q.pop();
    }
    return q;
}


// Print
void print(queue<int> q){
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}




// Driver code
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
    cout<<"Enter k: ";
    int k;
    cin>>k;

    queue<int> ans=reverseFirstK(q,k);
    print(ans);
}