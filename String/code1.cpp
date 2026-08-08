#include<iostream>
#include<cstring>
using namespace std;
 

int main(){
    
    // string str;
    // getline(cin,str,'&');
    // cout<<str<<endl;
    // return 0;
    string str ="Hello World";
    // for(int i=0;i<str.length();i++){
    //     cout<<str[i]<<" ";
    // }
    for(char ch:str){
        cout<<ch<<"-";
    }
    cout<<endl;
    return 0;
}