#include <iostream>

using namespace std;
int sum(int arr[],int n,int pos){
    if(pos==n) return 0;
    return sum(arr,n,pos+1)+arr[pos];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<sum(arr,n,0)<<'\n';
}