#include <iostream>
#define mex 8
using namespace std;
struct node{
    int data;
    node *next,*prev;
    node(){
        this->next=this;
        this->prev=this;
    }
    node(int x){
        this->data=x;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
struct sys{
    node *root;
    int size;
};
void enqueue(sys &s, int x){
    if(s.size>7) return;
    if(s.size==0){
        s.root->next=new node(x);
        node *temp=s.root->next;
        temp->next=s.root;
        temp->prev=s.root;
        s.root->prev=temp;
    }else{
        node * temp=s.root->next;
        s.root->next=new node(x);
        s.root->next->next=temp;
        s.root->next->prev=s.root;
        temp->prev=s.root->next;
    }
    s.size++;
}
void dequeue(sys &s){
    if(s.size==0) return;
    node *temp=s.root->prev;
    s.root->prev=temp->prev;
    s.root->prev->next=s.root;
    delete(temp);
    s.size--;
}
int top(sys &s){
    return s.root->prev->data;
}
void push(sys &s,int x){
    enqueue(s,x);
}
void pop(sys &s){
    if(s.size==0) return;
    node *temp=s.root->next;
    s.root->next=temp->next;
    s.root->next->prev=s.root;
    delete(temp);
    s.size--;
}
void printsys(sys &s){
    node *temp=s.root->prev;
    while(temp!=s.root){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
int main(){
    sys k;
    k.size=0;
    k.root=new node();
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        if(c=='E'){
            int x;
            cin>>x;
            enqueue(k,x);
        }if(c=='D'){
            dequeue(k);
        }
        if (c=='P'){
            int x;
            cin>>x;
            push(k,x);
        }
        if(c=='O'){
            pop(k);
        }
    }
    printsys(k);
}