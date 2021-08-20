#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

void insert(node &head,int value){
    node *temp=&head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new node();
    temp->next->data=value;
    temp->next->next=nullptr;
}
void initialize(node *arr, int n){
    for(int i=0;i<n;i++){
        arr[i].data=0;
        arr[i].next=nullptr;
    }
}
void printReverse(node *head,bool flip){
    if(head==nullptr){
        return;
    }
    printReverse(head->next,!flip);
    if(flip){
        for(int i=0;i<head->data;i++){
            cout<<"0";
        }
    }else{
        for(int i=0;i<head->data;i++){
            cout<<".";
        }
    }
}
void print(node *arr, int n){
    for(int i=0;i<n;i++){
        printReverse(arr[i].next,1);
        cout<<"\n";
    }
}

void print_reverse(node *head){
    node *temp=head;
    bool flipflop=1;
    while(temp!=nullptr){
        int data=temp->data;
        if(flipflop){
            for(int i=0;i<data;i++){
                cout<<"0";
            }
        }else{
            for(int i=0;i<data;i++){
                cout<<".";
            }
        }
        temp=temp->next;
        flipflop=!flipflop;
    }
    cout<<"\n";
}


int main(){
    int n,m;
    cin>>n>>m;
    node arr[n];
    initialize(arr,n);
    for(int i=0;i<n;i++){
        int counter=1;
        char prev;
        cin>>prev;
        for(int j=1;j<m;j++){
            char x;
            cin>>x;
            if(x==prev){
                counter++;
            }else{
                insert(arr[i],counter);
                counter=1;
            }
            prev=x;
        }
        insert(arr[i],counter);
    }
    print(arr,n);

}