#include <iostream>
using namespace std;
struct stack{
    int arr[1000];
    int size=0;
};
void push(stack &s, int value){
    if(s.size==1000) return;
    s.arr[s.size]=value;
    s.size++;
}
void pop(stack &s){
    if(s.size==0) return;
    s.size--;
}
int max(int a, int b){
    return (a>b?a:b);
}
int min(int a, int b){
    return (a<b?a:b);
}

int maximum(int w,int n, int *arr, int pos){
    if(pos>n || w<0) return -10000;
    if(w>=0 && pos==n){
        return 0;
    }
    return max(maximum(w-arr[pos],n,arr,pos+1)+arr[pos],maximum(w,n,arr,pos+1));
}
stack st,maxprofit;
void printstack(stack &st){
    while(st.size--){
        cout<<st.arr[st.size]<<" ";
    }
}
int maximumprofit=0;
void findpath(int sum,int n, int *arr, int pos){
    if(pos>n) return;
    if(sum==0 && maximumprofit<st.size){
        maximumprofit=st.size;
        maxprofit=st;
        return;
    }
    push(st,arr[pos]);
    findpath(sum-arr[pos],n,arr,pos+1);
    pop(st);
    findpath(sum,n,arr,pos+1);
}
int main(){
    int w,n;
    cin>>w>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m=maximum(w,n,arr,0);
    cout<<m<<"\n";
    findpath(m,n,arr,0);
    printstack(maxprofit);
    cout<<"Sum: "<<m<<"\n";
}