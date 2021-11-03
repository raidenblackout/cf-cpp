#include <iostream>

using namespace std;
int is_prime(int n, int l){
    if(n<2) return 0;
    if(n==2) return 1;
    if(n%l==0) return 0;
    if(l*l>n) return 1;
    return is_prime(n,l+1);
}
int main(){
    int n;
    cin>>n;
    if(is_prime(n,2)){
        cout<<"It's a prime\n";
    }else{
        cout<<"It's not a prime\n";
    }
}