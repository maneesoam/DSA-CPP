#include<iostream>
using namespace std; 
#define size 5
int f =-1,r=-1;
int q[size];
bool isempty(){
    if(f>r||f==-1){
        cout<<"queue is empty"<<endl;
        return true;
    }
    else{
        return false;
    }
}
    bool isfull(){
        if(r== size-1){
            cout<<"queue is full"<<endl;
            return true;

        }
        else{
            return false;

        }
    }
        void enqueue(int x){
            if(isfull()){
            cout<<"over flow"<<endl;
        }

        
        else{
            if (f==-1)
            f=0;
            r = r+1;
            q[r]=x;
        }
    }
    void dequeue(){
        if(isempty()){
            cout<<"underflow"<<endl;
        }
        else{
        int x = q[f];
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            f=f+1;
        }
        }

    }

    void traverse(){
        if(!isempty()){
            for(int i=f; i<=r; i++){
                cout<<q[i]<<" ";
            }
            cout<<endl;
        }
    }

    int main(){
        enqueue(10);
        enqueue(20);
        enqueue(30);
        enqueue(40);
        enqueue(50);
        traverse();
        enqueue(70);

        dequeue();
        traverse();
         dequeue();
          dequeue();
           dequeue();
            dequeue();
            enqueue(60);
            enqueue(80);


        
    }
    
