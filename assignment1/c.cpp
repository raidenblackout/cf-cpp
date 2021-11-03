#include <iostream>
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
const int int_max = 1e8;
int counts[int_max];
int main(){
    srand(777);
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];
    cout<<"Array 1: ";
    printArray(arr1,n);
    cout<<"Array 2: ";
    printArray(arr2,n);
    cout<<"Intersections: ";
    for(int i=0;i<n;i++) counts[arr1[i]]++;
    for(int i=0;i<n;i++){
        if(counts[arr2[i]]==1){
            cout<<arr2[i]<<" ";
        }
    }
    cout<<"\n";

}