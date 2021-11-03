#include <iostream>

using namespace std;

long long fact(int n){
    if(n==1 || n==0) return 1;
    return n*fact(n-1);
}
long long dp[(int)1e8];
long long fibo(int n){
    if(n==1) return 0;
    if(dp[n]!=0) return dp[n];
    dp[n]=fibo(n-1)+fibo(n-2);
    return dp[n];
}

void func(int n){
    cout<<"Hello ";
    if(n==7) return;
    func(n+1);
    cout<<"World ";
    cout<<n<<" ";
}
int main(){
    dp[2]=1;
    int n;
    cin>>n;
    // fibo(n);
    // for(int i=1;i<=n;i++) cout<<dp[i]<<"\n";
    func(5);
}