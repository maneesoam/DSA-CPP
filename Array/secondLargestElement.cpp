#include <iostream>
using namespace std; 
int main(){
   int arr [5] = {1,2,3,4,5};
 int n = sizeof(arr)/sizeof(arr[0]);
 int max = arr[0];
 int secondMax = arr[0];
  for(int i=0; i<n; i++){
    if(arr[i]>max){
      secondMax = max;
      max = arr[i];

    }
    else if (arr[i]>secondMax && arr[i]!=max){
      secondMax = arr[i];

    }

  }
  if (max == secondMax){
    cout<<"No second largest Element is exist";
  }
  else{
    cout<<"Second largest Element is "<<secondMax<<endl;
  }

}