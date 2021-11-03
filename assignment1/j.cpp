#include <iostream>
#include <string.h>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
int abs(int x){
    if(x<0) return -x;
    return x;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    int diff=INT_MAX;
    for(int i=1;i<n;i++){
        diff=(diff>abs(arr[i]-arr[i-1])?abs(arr[i]-arr[i-1]):diff);
    }
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])==diff){
            cout<<arr[i-1]<<" "<<arr[i]<<" ";
            break;
        }
    }
}