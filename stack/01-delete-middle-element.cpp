#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int>& inputStack,int count,int N){
   if (count==N/2){
      inputStack.pop();
      return ;
   }
   int num=inputStack.top();
   inputStack.pop();
   solve(inputStack,count+1,N);
   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack,count,N);
   
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
    deleteMiddle(s,n);
    print(s);
    return 0;
}