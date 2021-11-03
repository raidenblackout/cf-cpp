#include <iostream>
#include <string.h>

using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void removeDupes(int arr[],int &n,int pos, int counts[]){
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int mSize=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mSize=max(mSize,arr[i]);
    }
    printArray(arr,n);
    int counts[mSize+1];
    memset(counts,0,sizeof(counts));
    for(int i=0;i<n;i++){
        counts[arr[i]]++;
        if(counts[arr[i]]>1){
            removeDupes(arr,n,i,counts);
            i--;
        }
    }
    printArray(arr,n);
}