#include <iostream>

using namespace std;

int largest(int arr[],int pos, int n){
    if(pos>n){
        return 0;
    }
    if(pos==n) return arr[pos];
    int mid=(pos+n)/2;
    int fhalf=largest(arr,pos,mid);
    int lhalf=largest(arr,mid+1,n);
    return (fhalf>lhalf?fhalf:lhalf);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<largest(arr,0,n-1)<<"\n";
}