#include<iostream>
using namespace std;


class CircularQueue{
    int size;
    int *arr;
    int front;
    int rear;
    public:
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        rear=-1;
        front=-1;
    }
    bool enqueue(int value){
        //to check wheather queue is full
        if ((front==0 && rear==size-1) || (rear==(front-1)%(size-1))){
            return 0;
        }
        else if (front==-1){//first element to push
            front=rear=0;
        }
        else if (rear==size-1 && front!=0){//to maintain cycle nature
            rear=0;
        }
        else{//normal flow
            rear++;
        }
        //push inside queue
        arr[rear]=value;
        return 1;
    }
    int dequeue(){
        if (front==-1){//to check if queue is empty
            return -1;
        }
        int ans=arr[front];
        arr[front]=-1;
        if (front==rear){//to check if single element is present
            front=rear=-1;
        }
        else if (front==size-1){//to maintain cycle nature
            front=0;
        }
        else{
            front++;
        }
        return ans;
    }
};

//Driver code
int main(){
    CircularQueue q(5);
    cout<<q.enqueue(100)<<endl;
    cout<<q.enqueue(200)<<endl;
    cout<<q.enqueue(300)<<endl;
    cout<<q.enqueue(400)<<endl;
    cout<<q.enqueue(500)<<endl;
    cout<<q.enqueue(600)<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
}