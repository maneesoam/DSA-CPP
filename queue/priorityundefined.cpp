#include <iostream>
using namespace std;

class priorityQueue {
    int data[100];
    int priority[100];
    int n;

    public:
    priorityQueue(){
        n=0;

    }
    void enqueue(int x,int p){
        if(n==100){
            cout<<"priority Queue Overflow";
            return;
        }
        data[n]=x;
        priority[n]=p;
        n++;
        cout << "element inserted successfully" << endl;
    }

    void dequeue(){
        if(n==0){
            cout << "priority Queue Underflow" << endl;
            return;
        }
        int pos=0;
        for(int i=1;i<n;i++){
            if(priority[i] > priority[pos]){
                pos = i;
            }
        }
        cout << "Dequeued element: " << data[pos] << endl;
        for(int i=pos;i<n-1;i++){
            data[i] = data[i+1];
            priority[i] = priority[i+1];
        }
        n--;
    }
    void display(){
        if(n==0){
            cout<<"priority Queue is empty"<<endl;
            return;

        }
        cout<<"Element priority"<<endl;
        for( int i=0;i<n;i++){
            cout<<data[i]<<" "<<priority[i]<<endl;
        }
    }
};
int main(){
    priorityQueue pq;
    int x,p;
    for( int i=0;i<4;i++){
        cout<<"enter elements:";
        cin>>x;
        cout<<"enter priority";
        cin>>p;
        pq.enqueue(x,p);
    }
    pq.display();
    cout<<"deleting highest priority element"<<endl;
    pq.dequeue();
    pq.display();
    cout<<"deleting highest priority elements"<<endl;
    pq.dequeue();
    pq.display();
    return 0;
}