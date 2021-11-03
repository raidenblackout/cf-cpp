#include <iostream>
#define mex 1000
using namespace std;
struct stack{
    int a[mex];
    int size;
};
stack st;
void push(int a){
    if(st.size>=mex) return;
    st.a[st.size]=a;
    st.size++;
}
void pop(){
    if(st.size==0) return;
    st.size--;
}
int top(){
    if(st.size==0) return -1;
    return st.a[st.size-1];
}
void insertlast(int x){
    if(st.size==0){
        push(x);
        return;
    }
    int k=top();
    pop();
    insertlast(x);
    push(k);
}
void reverse(){
    if(st.size==0) return;
    int x=top();
    pop();
    reverse();
    insertlast(x);
}
void printStack(){
    if(st.size==0) return;
    int x=top();
    cout<<x<<" ";
    pop();
    printStack();
    push(x);
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        push(k);
    }
    cout<<"Before: ";
    printStack();
    cout<<"\n";
    reverse();
    cout<<"After: ";
    printStack();
}