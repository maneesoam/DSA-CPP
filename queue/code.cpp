#include<iostream>
using namespace std; 
// FOR LARGEST NUMBER
int main(){
    int a,b,c;
    cin>>a>>b>>c;
//     if(a>b && a>c ){
//         cout<<"a is the largest";
//     }
//     else if(b>a && b>c){
//         cout<<"b is largest";
//     }
//     else {
//         cout<<"c is the largest";
//     }

// }
int choice = (a<b && a<c)?1:
(b<c && b<a)?2:3;
switch(choice){
    case 1: 
    cout<<"a is the smallest";
    break;
    case 2:
    cout<<"b is the smallest";
    case 3 :
    cout<<"c is the smallest";
    return 0;
}
}