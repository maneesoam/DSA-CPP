#include<iostream>
#include<cstring>
using namespace std;
bool isPalindrome(char str[],int n){
    int st=0,end=n-1;
    while(st<end){
        if(str[st++]!=str[end--]){
            cout<<"Not a Valid Palindrome";
            return false;

        }
    }
    cout<<"Valid Palindrome";
 return true;
}

int main(){
    char word[] ="MANEE";

isPalindrome(word,strlen(word));


    
}