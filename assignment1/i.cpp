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
            if(arr[j]<arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,n);
    int leftsum=0;
    for(int i=0;i<n;i++){
        leftsum+=arr[i];
        if(sum-leftsum<leftsum){
            cout<<i+1<<"\n";
            break;
        }
    }
}