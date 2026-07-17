#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>& s,int x){
    if (s.empty()){
        s.push(x);
        return ;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
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
    int element;
    cin>>element;
    pushAtBottom(s,element);
    print(s);
    return 0;
}