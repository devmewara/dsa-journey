#include<iostream>
using namespace std;

// Method -1 (Using stack)
void reverseQueue1(queue<int> &q) {
    stack<int> s;
    while (!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

// Method-2 (Using recursion)
void reverseQueue2(queue<int> &q) {
    if (q.empty()){
        return ;
    }
    int element=q.front();
    q.pop();
    reverseQueue2(q);
    q.push(element);
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

    reverseQueue1(q);
    print(q);
    reverseQueue2(q);
    print(q);
}