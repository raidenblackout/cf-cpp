#include <iostream>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
void callfibo(int n, int i){
    if(i==n) return;
    cout<<fibo(i)<<" ";
    callfibo(n,i+1);
}
int main(){
    int n;
    cin>>n;
    callfibo(n,0);
}