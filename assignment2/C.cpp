#include <iostream>

using namespace std;

struct node{
    int data;
    node *next,*prev;
};

node* search(node &head,int value){
    node *temp=head.next;
    while(temp!=nullptr){
        if(temp->data==value){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

void insert(node &head, int key_y, int key_x){
    node *temp=search(head,key_y);
    if(temp!=nullptr){
        cout<<"Insert after "<<temp->data<<"\n";
        node *p=temp->next;
        temp->next=new node();
        temp->next->data=key_x;
        temp->next->prev=temp;
        temp=temp->next;
        temp->next=p;
        if(p!=nullptr){
            p->prev=temp;
        }
    }else{
        cout<<"Insert after dummy node\n";
        node *p=head.next;
        head.next=new node();
        head.next->prev=&head;
        head.next->next=p;
        head.next->data=key_x;
        if(p!=nullptr){
            p->prev=head.next;
        }
    }
}
void del(node &head, int key_x){
    node *temp=search(head,key_x);
    if(temp!=nullptr){
        cout<<"Node with key value "<<temp->data<<" is Deleted\n";
        temp->prev->next=temp->next;
        if(temp->next!=nullptr){
            temp->next->prev=temp->prev;
        }
        delete(temp);
    }else{
        cout<<"Delete not possible\n";
    }
}
void print(node &head){
    node *temp=head.next;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node head;
    head.next=nullptr;
    head.prev=nullptr;
    head.data=0;
    while(true){
        string s;
        cin>>s;
        if(s=="ins"){
            int y,x;
            cin>>y>>x;
            insert(head,y,x);
        }else if(s=="del"){
            int x;
            cin>>x;
            del(head,x);
        }else if(s=="sch"){
            int x;
            cin>>x;
            if(search(head,x)!=nullptr){
                cout<<"Node with key value "<<x<<" is found\n";
            }else{
                cout<<"Not Found\n";
            }
        }else if(s=="shw"){
            print(head);
        }else if(s=="ext"){
            break;
        }
    }

}