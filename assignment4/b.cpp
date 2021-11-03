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
void sortedinsert(int x){
    if(st.size==0){
        push(x);
        return;
    }
    int k=top();
    if(k>x){
        push(x);
        return;
    }
    pop();
    sortedinsert(x);
    push(k);
}

void sortstack(){
    if(st.size==0) return;
    int x=top();
    pop();
    sortstack();
    sortedinsert(x);
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
    sortstack();
    cout<<"After: ";
    printStack();
}