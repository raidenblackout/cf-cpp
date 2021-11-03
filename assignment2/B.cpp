#include <iostream>

using namespace std;

struct node{
    int data;
    node *next,*prev;
};
int length(node &head){
    int len=1;
    node *temp=head.next;
    if(head.next==nullptr){
        return 0;
    }
    while(temp->next!=&head){
        temp=temp->next;
        len++;
    }
    return len;
}
void insert(node &head, int value){
    node *temp=head.next;
    if(temp==nullptr){
        (head.next)=new node();
        (head.next)->data=value;
        (head.next)->prev=&head;
        (head.next)->next=&head;
        (head.prev)=head.next;
        return;
    }
    if((head.next)->data>value){
        (head.next)=new node();
        (head.next)->data=value;
        (head.next)->prev=temp->prev;
        (head.next)->next=temp;
        temp->prev=head.next;
        return;
    }
    while(temp->next!=&head && temp->next->data<value){
        temp=temp->next;
    }
    node *p=temp->next;
    temp->next=new node();
    temp->next->prev=temp;
    temp=temp->next;
    temp->data=value;
    temp->next=p;
}
void print(node &head){
    node *temp=head.next;
    if(temp==nullptr){
        cout<<"Empty\n";
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=&head);
    cout<<"\n";
}
bool search(node &head,int value){
    node *temp=head.next;
    if(temp==nullptr){
        return 0;
    }
    do{
        if(temp->data==value){
            return 1;
        }
        temp=temp->next;
    }while(temp!=&head);
    return 0;
}
void delete_node(node &head,int value){
    node *temp=head.next;
    if(temp==nullptr){
        cout<<"Linked list is empty.\n";
        return;
    }
    if(temp->data==value){
        node *p=temp;
        if(length(head)==1){
            head.next=nullptr;
            head.prev=nullptr;
        }else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            head.next=temp->next;
        }
        delete(p);
        return;
    }
    while(temp->next!=&head && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==&head||temp->next->data!=value){
        return;
    }
    node *p=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete(p);
}
void initialize(node &head){
    head.next=nullptr;
    head.prev=nullptr;
    head.data=0;
}

int main() {
    node head;
    initialize(head);
    while(true){
        int choice;
        cin>>choice;
        if(choice==1){
            int x;
            cin>>x;
            insert(head,x);
        }else if(choice==2){
            print(head);
        }else if(choice==3){
            int x;
            cin>>x;
            if(search(head,x)){
                cout<<"Found\n";
            }else{
                cout<<"Not Found\n";
            }
        }else if(choice==4){
            int x;
            cin>>x;
            delete_node(head,x);
        }else if(choice==5){
            cout<<length(head)<<"\n";
        }else{
            break;
        }
    }
}
