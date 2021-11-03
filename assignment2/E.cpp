#include <iostream>

using namespace std;

struct node{
    char c;
    int frequency;
    node *next;
};

void update(node &head,char x){
    node *temp=head.next;
    while(temp->c!=x){
        temp=temp->next;
    }
    temp->frequency++;
}
void initialize(node &head){
    node *temp=&head;
    char c='a';
    while(c!='z'+1){
        temp->next=new node();
        temp=temp->next;
        temp->next=nullptr;
        temp->c=c;
        temp->frequency=0;
        c++;
    }
}
void print(node &head){
    node *temp=head.next;
    while(temp!=nullptr){
        cout<<temp->c<<" : "<<temp->frequency<<"\n";
        temp=temp->next;
    }
}
int main(){
    node head;
    initialize(head);
    string s;
    cin>>s;
    for(char c:s){
        if(c>='a' && c<='z' || c>='A' && c<='Z'){
            if(c>='A'&&c<='Z'){
                update(head,c+'a'-'A');
            }else{
                update(head,c);
            }
        }else{
            cout<<"INVALID INPUT\n";
            return 0;
        }
    }
    print(head);
}