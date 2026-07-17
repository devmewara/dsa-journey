#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &stack,int element){
	if (stack.empty()){
		stack.push(element);
		return ;
	}
	if (stack.top()<element){
		stack.push(element);
		return;
	}
	int num=stack.top();
	stack.pop();
	insert(stack,element);
	stack.push(num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if (stack.empty()){
		return ;
	}
	if (stack.size()==1){
		return ;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,num);
	
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
    sortStack(s);
    print(s);
    return 0;
}