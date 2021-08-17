#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
struct d_node{
    node *left,*right,*top,*bottom;
};
void initialize(d_node &head){
    head.left=head.right=head.top=head.bottom=nullptr;
}
void insert(node **head,int value){
    node *temp=*head;
    if(temp==nullptr){
        (*head)=new node();
        (*head)->data=value;
        (*head)->next=nullptr;
        return;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new node();
    temp=temp->next;
    temp->data=value;
}
int sum(node *head){
    int result=0;
    node *temp=head;
    while(temp!=nullptr){
        result+=temp->data;
        temp=temp->next;
    }
    return result;
}
void findmax(d_node &head){
    int results[4];
    string names[]={"Left","Right","Top","Bottom"};
    results[0]=sum(head.left);
    results[1]=sum(head.right);
    results[2]=sum(head.top);
    results[3]=sum(head.bottom);
    for(int i=0;i<4;i++){
        bool greater=1;
        for(int j=0;j<4;j++){
            if(i==j) continue;
            if(results[j]>results[i]){
                greater=0;
                break;
            }
        }
        if(greater){
            cout<<names[i]<<" Link List Has Maximum Sum "<<results[i]<<"\n";
            break;
        }
    }
}
int main(){
    d_node head;
    initialize(head);
    int n;
    cin>>n;
    while(n--){
        int value;
        char choice;
        cin>>choice>>value;
        if(choice=='L'){
            insert(&head.left,value);
        }else if(choice=='R'){
            insert(&head.right,value);
        }else if(choice=='T'){
            insert(&head.top,value);
        }else if(choice=='B'){
            insert(&head.bottom,value);
        }
    }
    findmax(head);

}