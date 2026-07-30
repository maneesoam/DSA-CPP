#include <iostream>
#include<climits>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n; i++){
        cout<<arr[i]<<" ";
    }
}
void countingSort(int arr[], int n){
    int freq[10000] = {0};
    int minValue =INT_MAX;
    int maxValue = INT_MIN;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        maxValue = max(maxValue,arr[i]);
        minValue = min(minValue,arr[i]);
    }
    int j =0;
    for(int i = minValue;i<=(maxValue); i++){
while(freq[i]>0){
    arr[j++] =i;
    freq[i]--;
}

    }
    print(arr,n);
}

int main(){
    int arr[]= {5,4,1,3,2};
    countingSort(arr,5);
    return 0;
}