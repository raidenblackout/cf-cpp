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

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

void randGen(int n){
    FILE *f;
    f=fopen("in.txt","w");
    for(int i=0;i<n;i++){
        fprintf(f,"%d ",rand()%(250+249+1)-249);
    }
    fclose(f);
}

int main(){
    int n=500;
    randGen(n);
    FILE *f=fopen("in.txt","r");
    FILE *o=fopen("out.txt","w");
    int arr[n];
    for(int i=0;i<n;i++) fscanf(f,"%d",&arr[i]);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++) fprintf(o,"%d ",arr[i]);
    fclose(f);
    fclose(o);
}