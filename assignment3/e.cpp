#include <iostream>

using namespace std;

void decimaltobinary(int n){
    if(n==0) return;
    decimaltobinary(n/2);
    cout<<n%2;
}

int main(){
    int n;
    cin>>n;
    decimaltobinary(n);
}