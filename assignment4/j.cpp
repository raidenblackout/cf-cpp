#include <iostream>
#define mex 52
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
void insertfirst(sys &s, int x){
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
void removelast(sys &s){
    if(s.size==0) return;
    node *temp=s.root->prev;
    s.root->prev=temp->prev;
    s.root->prev->next=s.root;
    delete(temp);
    s.size--;
}
int top(sys &s){
    return s.root->next->data;
}
void insertlast(sys &s, int x){
    if(s.size==0){
        s.root->next=new node(x);
        node *temp=s.root->next;
        temp->next=s.root;
        temp->prev=s.root;
        s.root->prev=temp;
    }else{
        node * temp=s.root->prev;
        s.root->prev=new node(x);
        s.root->prev->prev=temp;
        s.root->prev->next=s.root;
        temp->next=s.root->prev;
    }
    s.size++;
}
void removefirst(sys &s){
    if(s.size==0) return;
    node *temp=s.root->next;
    s.root->next=temp->next;
    s.root->next->prev=s.root;
    delete(temp);
    s.size--;
}
int main(){
    while(1){
        sys s;
        s.root=new node();
        s.size=0;
        int n;
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;i++){
            insertlast(s,i);
        }
        cout<<"Discard Cards: ";
        while(s.size>=2){
            int first=top(s);
            removefirst(s);
            cout<<first<<(s.size>=2?", ":" ");
            first=top(s);
            removefirst(s);
            insertlast(s,first);
        }
        cout<<"\nRemaining Card: "<<top(s)<<"\n";
    }
    
}