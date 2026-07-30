#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void Uppercase(char word[],int n){
    for(int i=0;i<n;i++){
        char ch =word[i];
        if(ch>='A'&&ch<='Z'){
            continue;
        }
        else{
            word[i]=ch-'a'+'A';
        }
    }
}
int main(){
    char word[]="APple";
    Uppercase(word,strlen(word));
    cout<<word<<endl;
    return 0;
}