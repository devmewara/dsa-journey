#include<iostream>
#include<queue>
using namespace std;

class Queue{
    //properties
    public:
        int *arr;
        int size;
        int front;
        int rear;

    //behaviour
    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void push(int element){
        if (rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=element;
            rear++;
        }
    }
    void pop(){
        if (isEmpty()){
            cout<<"Empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if (front==rear){
                rear=0;
                front=0;
            }
        }
    }
    int frontElement(){
        if (isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty(){
        if (front==rear){
            return 1;
        }
        else{
            return 0;
        }
    }
     
};

int main(){

    // Implementing queue using array

    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"Front: "<<q.frontElement()<<endl;
    q.pop();
    cout<<"Front: "<<q.frontElement()<<endl;
    q.push(4);
    q.push(5);
    if (q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    if (q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    q.pop();

    // STL
    /*queue<int> q;
    q.push(1);
    cout<<"Front of queue is: "<<q.front()<<endl;
    q.push(2);
    cout<<"Front of queue is: "<<q.front()<<endl;
    q.push(3);
    cout<<"Front of queue is: "<<q.front()<<endl;
    cout<<"Size of queue: "<<q.size()<<endl;
    q.pop();
    cout<<"Size of queue: "<<q.size()<<endl;
    cout<<"Front of queue is: "<<q.front()<<endl;
    if (q.empty()){
        cout<<"Empty"<<endl;
    }else{
        cout<<"Not empty"<<endl;
    }
    */

}