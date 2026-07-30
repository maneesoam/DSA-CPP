#include<iostream>
#include<climits>
using namespace std;

void printMaxSubarray(int arr[],int n){
    int maxsum = INT_MIN;
        for(int start =0; start<n; start++){
        for(int end= start; end<n; end++){
         int currsum =0;
          for(int i =start;i<=end;i++){
           currsum += arr[i];
            } 
            cout<<currsum<<" ,";
           maxsum = max(currsum,maxsum);
            
        }
        cout<<endl;  
           
    }
    cout<<"Maximum Subarray Sum is ="<<maxsum<<endl;
}
int main(){
    int arr[]={2,-3,6,-5,4,2};
    int n = 6;
    printMaxSubarray(arr,n);
}