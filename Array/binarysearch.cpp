#include <iostream>
using namespace std; 
 int binarySearch(int arr[],int n,int key){
    
    
    int st = 0;
    int end = n-1;
    while(st<=end){
        int mid = (st + end)/2;
        if(arr[mid]==key ){
            return mid;
        }
        else if(arr[mid]<key){
            st = mid +1;

        }
        else{
            end = mid-1;
        }
    }
    return -1;
 }

 int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int key = 6;
   
     int result = binarySearch(arr,n,key);
    if(result!=-1){
        cout<<"Element Found at index :"<<result<<endl;
    }
    else{
        cout<<"Element Not Found:"<<endl;
    }
    return 0;
 }