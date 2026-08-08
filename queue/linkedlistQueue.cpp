#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

};
class Queue{
    private:
    Node *front;
    Node *rear;
    public:
    Queue(){
        front = NULL;
        rear = NULL;

    }
    void enqueue(int value){
        Node *newNode= new Node;
        newNode->data =value;
        newNode->next= NULL;
        if(front ==NULL){
            front =newNode;
            rear = newNode;

        }
        else{
            rear->next =newNode;
            rear = newNode;
        }
        cout<<value<<" is inserted into the queue"<<endl;

    }
    void dequeue(){
        if(front == NULL){
            cout<<"Queue Underflow"<<endl;

        }
        Node *temp = front;
        cout<<temp->data<<" is deleted from the queue"<<endl;
        front =front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
    }
    void peek(){
        if(front==NULL){
            cout<<"queue is empty!"<<endl;

        }
        else{
            cout<<"front element is "<<front->data<<endl;        
        }
    }
    void display(){
        if (front==NULL){
            cout<<"queue is empty"<<endl;
            return;

        }
        Node *temp = front;
        cout<<"queue elements are :";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp =temp->next;
        }
        cout<<endl;
    }
    void isEmpty(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.peek();
    q.isEmpty();
    return 0;
}