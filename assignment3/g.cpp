#include <iostream>
using namespace std;
void reversenumber(int n){
    if(n==0) return;
    cout<<n%10;
    reversenumber(n/10);
}
int main(){
    int n;
    cin>>n;
    reversenumber(n);
}