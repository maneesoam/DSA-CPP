#include<iostream>
using namespace std;
void printMaxSubarray(int arr[],int n){
    int maxsum = INT8_MIN;
        for(int start =0; start<n; start++){
            int currsum =0;
        for(int end= start; end<n; end++){
         currsum=+arr[end];
           maxsum = max(currsum,maxsum);
            
        }
           
    }
    cout<<"Maximum Subarray Sum is ="<<maxsum<<endl;
}
int main(){
    int arr[]={2,-3,6,-5,4,2};
    int n = 6;
    printMaxSubarray(arr,n);
}