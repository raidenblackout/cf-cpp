#include <iostream>
using namespace std;

int power(int n, int p){
    if(p==0) return 1;
    int x=power(n,p/2);
    if(p%2==0) return x*x;
    else return n*x*x;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<power(n,p);
}