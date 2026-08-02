#include<iostream>
#include<cstring>
using namespace std;
 

int main(){
    char str1[100]= "Hello";
    char str2[100]="World";
    strcat(str1,str2);
    cout<<str1<<endl;
    return 0;
}