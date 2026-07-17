#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &stack,int n){
    if (stack.empty()){
        stack.push(n);
        return ;
    }
    int num=stack.top();
    stack.pop();
    insertAtBottom(stack,n);
    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty()|| stack.size()==1){
        return;
    }
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);
}


//Driver Code

void takeInput(stack<int> &s,int n){
    for (int i=0;i<n;i++){
        int value;
        cin>>value;
        s.push(value);
    }
}
void print(stack<int> s){
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    takeInput(s,n);
    reverseStack(s);
    print(s);
    return 0;
}