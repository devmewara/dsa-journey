#include<iostream>
#include<stack>
using namespace std;
class Stack{
    //properties
    public:
        int *arr;
        int size;
        int top;

    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if (size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    void pop(){
        if (isEmpty()){
            cout<<"Underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        if (isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    bool isEmpty(){
        if (top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
     
};
int main(){


    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<"Peek: "<<st.peek()<<endl;
    st.pop();
    cout<<"Peek: "<<st.peek()<<endl;
    st.push(4);
    st.push(5);
    if (st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    if (st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    st.pop();


    /*
    //creation of stack
    stack<int> s;
    //stack operations
    s.push(1);
    s.push(2);
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    if (s.empty()){
        cout<<"Stack empty"<<endl;
    }
    else{
        cout<<"Stack not empty."<<endl;
    }
    cout<<"Size of stack: "<<s.size()<<endl;
    */



}