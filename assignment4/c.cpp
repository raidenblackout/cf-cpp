#include <iostream>
#define mex 1000
using namespace std;
struct queue{
    int arr[mex];
    int size,s,l;
};
void enqueue(queue &q,int x){
    if(q.size>0 && q.s==q.l){
        cout<<"QUEUE FULL\n";
        return;
    }
    q.arr[q.l]=x;
    q.l=(q.l+1)%mex;
    q.size++;
}
void dequeue(queue &q){
    if(q.size==0){
        cout<<"QUEUE EMPTY\n";
        return;
    }
    q.s=(q.s+1)%mex;
    q.size--;
}
int top(queue &q){
    if(q.size==0){
        return -1;
    }
    return q.arr[q.s];
}
struct stack{
    queue q1,q2;
};
void push(stack &st,int data){
    if(st.q1.size>0){
        while(st.q1.size>0){
            enqueue(st.q2,top(st.q1));
            dequeue(st.q1);
        }
        enqueue(st.q1,data);
        while(st.q2.size>0){
            enqueue(st.q1,top(st.q2));
            dequeue(st.q2);
        }
    }else{
        enqueue(st.q1,data);
    }
}
void pop(stack &st){
    dequeue(st.q1);
}
int top(stack &st){
    return top(st.q1);
}
void init(stack &st){
    st.q1.size=st.q1.l=st.q1.s=0;
    st.q2.size=st.q2.l=st.q2.s=0;
}
int size(stack &st){
    return st.q1.size;
}
int main(){
    stack st;
    init(st);
    while(true){
        cout<<"Press 1 to insert into stack or 2 to print and exit: \n";
        int x;
        cin>>x;
        if(x==1){
            int k;
            cin>>k;
            push(st,k);
        }
        if(x==2) break;
    }
    cout<<"Stack: ";
    while(size(st)){
        int x=top(st);
        cout<<x<<" ";
        pop(st);
    }

}