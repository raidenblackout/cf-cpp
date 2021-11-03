#include <iostream>
using namespace std;
int bsearch(int arr[],int l, int r, int n, int value){
    int mid=l+(r-l)/2;
    if(arr[mid]==value) return mid;
    if(l==r) return -1;
    if(value>arr[mid]){
        return bsearch(arr,mid+1,r,n,value);
    }else{
        return bsearch(arr,l,mid,n,value);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int value;
    cin>>value;
    int k=bsearch(arr,0,n-1,n,value);
    if(k!=-1){
        cout<<"Found at position "<<k<<"\n";
    }else{
        cout<<"Not found\n";
    }
}