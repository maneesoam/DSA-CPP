#include<iostream>
using namespace std;
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n-1;
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
        printArr(arr,n);
             
        return 0;
    
}
// #include<iostream>
// using namespace std;
// void printArr(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<", ";
//     }
//     cout<<endl;
// }
// int main(){
//     int arr[] = {5,4,3,9,2};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int copyArr[n];
//     for(int i =0; i<n; i++){
//         int j = n-i-1;
//         copyArr[i] = arr[j];
//     }
//         for(int i=0; i<n; i++){
//             arr[i] = copyArr[i];

//         }
//         printArr(arr,n);
             
//         return 0;
    
// }