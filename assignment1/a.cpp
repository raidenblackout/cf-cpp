#include <iostream>
#include <string.h>
using namespace std;

void generateRandom(int arr[],int n){
    srand(1e9+7);
    for(int i=0;i<n;i++){
        arr[i]=rand()%n+1;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    generateRandom(arr,n);
    printArray(arr,n);
    int counts[n+1];
    memset(counts,0,sizeof(counts));
    for(int i=0;i<n;i++){
        counts[arr[i]]++;
        if(counts[arr[i]]>1){
            cout<<"index: "<<i<<" value: "<<arr[i]<<"\n";
        }
    }
}