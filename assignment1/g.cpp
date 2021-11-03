#include <iostream>
#include <string.h>
using namespace std;
void printArray(char arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void swap(char &a, char &b){
    char temp=a;
    a=b;
    b=temp;
}

void randGen(int n){
    FILE *f;
    f=fopen("in.txt","w");
    for(int i=0;i<n;i++){
        char x='A'+rand()%(26);
        fprintf(f,"%c ",x);
    }
    fclose(f);
}
void replacement_sort(char arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
    }
}
int main(){
    int n=1000;
    randGen(n);
    FILE *f=fopen("in.txt","r");
    char arr[n];
    for(int i=0;i<n;i++) fscanf(f,"%c ",&arr[i]);
    replacement_sort(arr,n);
    printArray(arr,n);
    fclose(f);
}