#include<iostream>
#include<cstring>
using namespace std;
int main(){

   char sentence[30];
   cin.getline(sentence,30,'*');
   cout<<"Your word was: "<<sentence<<endl;
   cout<<strlen(sentence)<<endl;
    return 0;
    
} 