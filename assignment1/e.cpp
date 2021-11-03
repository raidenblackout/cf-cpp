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

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    printArray(arr,n);
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    printArray(arr,n);
}