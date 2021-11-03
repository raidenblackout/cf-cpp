#include <iostream>

using namespace std;

void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int bsearch(int arr[],int n, int item){
    int low=0, high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==item){
            return 1;
        }
        if(arr[mid]<item){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return 0;
}

int main(){
    int n,item;
    cin>>n>>item;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
    if(bsearch(arr,n,item)){
        cout<<"Found\n";
    }else{
        cout<<"Not found\n";
    }
}