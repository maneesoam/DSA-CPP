#include <bits/stdc++.h>
using namespace std;
void fn1(int n){
    if(n==0){
        return;
    }
    else{
        cout<<n<<" ";
        fn1(n-1);
    }
    cout<<endl;


}
void fn2(int n){
    if(n==0){
        return;
    }
    else{
        fn2(n-1);
        cout<<n<<" ";
        
    }


}



int main(){
     fn1(5);
    fn2(5);

}