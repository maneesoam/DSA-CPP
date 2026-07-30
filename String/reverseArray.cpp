#include<iostream>
#include<cstring>
using namespace std;
void reverse(char word[],int n){
    int str =0,end=n-1;
    for(int i=0;i<n;i++){
        while(str<end){
            swap(word[str++],word[end--]);
            
            
        }
    }
}
int main(){
    char word[]="MANEE";
    
    reverse(word,strlen(word));
    cout<<word<<endl;

}