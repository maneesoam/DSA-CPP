#include <iostream>
using namespace std; 
void printArr(int arr[] , int n){
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}



void func(int arr[]){

arr[0] = 1000;

}

int main() {
    int a =5;
    int *ptr = &a;
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr,n);
     func(arr);
    cout<<arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*(arr +1)<<endl;
    cout<<*(arr + 2)<<endl;
    cout<<*ptr<<endl;
    int max = arr[0];
    int min = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i]>max){
            max = arr[i];
            // cout<<"assigning value "<<arr[i]<<" to max"<<endl;
        }
        if(arr[i]< min){
            min = arr[i];

        }
        
    }
    cout<<"Largest = "<<max<<endl;
    cout<<"Smallest = "<<min<<endl;
    
   
    return 0;
}