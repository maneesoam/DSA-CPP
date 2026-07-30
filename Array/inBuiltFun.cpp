#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

void print(int arr[],int n){
for(int i =0;i<n;i++){
    cout<<arr[i]<<" ";
}
 cout<<endl;
}



int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    sort(arr, arr+n);
    // sort(arr, arr+n, greater<int>());
print(arr,5);
return 0;
}