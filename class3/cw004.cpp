#include <iostream>

using namespace std;

struct list{
    int data;
    list *next;
};
typedef struct list node;

void display(node *start){
    cout<<"The nodes are: ";
    node *temp=start;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

void insert(node **start, int value){
    node *temp=*start;

    if(*start==nullptr){
        (*start)=new node();
        (*start)->data=value;
        (*start)->next=nullptr;
        return;
    }

    if((*start)->data>=value){
        temp=new node();
        temp->data=value;
        temp->next=*start;
        *start=temp;
    }else{
        while(temp->next!=nullptr && temp->next->data<=value){
            temp=temp->next;
        }
        node *p=temp->next;
        temp->next=new node();
        temp=temp->next;
        temp->data=value;
        temp->next=p;
    }
}
void deletion(node **start, int value){
    if((*start)==nullptr){
        cout<<"Not found\n";
        return;
    }

    if((*start)->data==value){
        node *temp=*start;
        (*start)=(*start)->next;
        delete(temp);
        return;
    }

    node *temp=*start;
    while(temp->next!=nullptr && temp->next->data!=value){
            temp=temp->next;
    }

    if(temp->next==nullptr){
        cout<<"Not found\n";
        return;
    }
    node *p=temp->next;
    temp->next=temp->next->next;
    delete(p);
}

void showmenu(node **start){
    do{
        int choice;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            int value;
            cout<<"Enter value: ";
            cin>>value;
            insert(start,value);
            display(*start);
        }

        if(choice==2){
            int value;
            cout<<"Enter value: ";
            cin>>value;
            deletion(start,value);
            display(*start);
        }

        if(choice==3){
            break;
        }
    }while(1);
}

int main(){
    node *start=nullptr;
    showmenu(&start);
}