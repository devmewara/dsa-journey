#include<iostream>
using namespace std;
 
class Deque
{
    int size;
    int *arr;
    int front;
    int rear;
    int count;
public:
    Deque(int n)
    {
        size=n;
        arr=new int[size];
        front=rear=-1;
        count=0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull()){
            return 0;
        }
        if (isEmpty()){
            front=rear=0;
            arr[front]=x;
            count++;
            return 1;
        }
        if (front==0){
            front=size-1;
            arr[front]=x;
            count++;
            return 1;
        }
        front--;
        arr[front]=x;
        count++;
        return 1;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull()){
            return 0;
        }
        if (isEmpty()){
            front=0;
            rear=0;
            arr[rear]=x;
            count++;
            return 1;
        }
        if (rear==size-1){
            rear=0;
            arr[rear]=x;
            count++;
            return 1;
        }
        rear++;
        arr[rear]=x;
        count++;
        return 1;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty()){
            return -1;
        }   
        int e=arr[front];
        if (front==size-1){
            front=0;
            count--;
            return e;
        }
        front++;
        count--;
        if (count==0){
            front=rear=-1;
        }
        return e;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty()){
            return -1;
        }
        int e=arr[rear];
        if (rear==0){
            rear=size-1;
            count--;
            return e;
        }
        rear--;
        count--;
        if (count==0){
            front=rear=-1;
        }
        return e;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty()){
            return -1;
        }
        return arr[front];

    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (count==0){
            return 1;
        }
        return 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if (count==size){
            return 1;
        }
        return 0;
    }
};


// Driver code
int main(){
    Deque d(5);
    d.pushFront(100);
    d.pushFront(200);
    d.pushRear(300);
    cout<<"Front: "<<d.getFront()<<endl;
    cout<<"Rear: "<<d.getRear()<<endl;
    cout<<"Front element deleted: "<<d.popFront()<<endl;
    cout<<"Rear element deleted: "<<d.popRear()<<endl;
    cout<<"Front: "<<d.getFront()<<endl;
    cout<<"Rear: "<<d.getRear()<<endl;
    d.pushFront(400);
    d.pushRear(500);
    cout<<"Front: "<<d.getFront()<<endl;
    cout<<"Rear: "<<d.getRear()<<endl;
}