#include <iostream>

using namespace std;

struct node{
    int coefficient,exponent;
    node *next;
};

void insert(node &head,int coefficient,int exponent){
    node *temp=&head;
    while(temp->next!=nullptr && temp->next->exponent>=exponent){
        temp=temp->next;
    }
    if(temp->exponent==exponent){
        temp->coefficient+=coefficient;
    }else{
        node *p=temp->next;
        temp->next=new node();
        temp->next->next=p;
        temp->next->coefficient=coefficient;
        temp->next->exponent=exponent;
    }
}

node calculate(node &first, node &second){
    node *temp1=first.next,*temp2=second.next;
    node results;
    results.next=nullptr;
    node *temp3=&results;
    while(temp1!=nullptr || temp2!=nullptr){
        temp3->next=new node();
        temp3->next->next=nullptr;
        if((temp1!=nullptr && temp2!=nullptr)){
            if(temp1->exponent==temp2->exponent){
                temp3->next->exponent=temp1->exponent;
                temp3->next->coefficient=temp1->coefficient+temp2->coefficient;
                temp1=temp1->next;
                temp2=temp2->next;
            }else if(temp1->exponent>temp2->exponent){
                temp3->next->exponent=temp1->exponent;
                temp3->next->coefficient=temp1->coefficient;
                temp1=temp1->next;
            }else if(temp2->exponent>temp1->exponent){
                temp3->next->exponent=temp2->exponent;
                temp3->next->coefficient=temp2->coefficient;
                temp2=temp2->next;
            }
        }else if(temp1==nullptr){
            temp3->next->exponent=temp2->exponent;
            temp3->next->coefficient=temp2->coefficient;
            temp2=temp2->next;
        }else if(temp2==nullptr){
            temp3->next->exponent=temp1->exponent;
            temp3->next->coefficient=temp1->coefficient;
            temp1=temp1->next;
        }
        temp3=temp3->next;
    }
    return results;
}

void print(node &head){
    node *temp=head.next;
    while(temp!=nullptr){
        if(temp->exponent==0){
            cout<<temp->coefficient<<(temp->next==nullptr?"":"+");
        }else{
            cout<<temp->coefficient<<"X^"<<temp->exponent<<(temp->next==nullptr?"":"+");
        }
        temp=temp->next;
    }
    cout<<'\n';
}

int main(){
    node first,second;
    first.next=second.next=nullptr;
    cout<<"For the first Expression: \n";
    while(true){
        cout<<"Enter 1 to continue or 2 to exit\n";
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"Enter coefficient and exponent:\n";
            int coeff,exp;
            cin>>coeff>>exp;
            insert(first,coeff,exp);
        }else if(choice==2){
            break;
        }
    }
    cout<<"For the second Expression: \n";
    while(true){
        cout<<"Enter 1 continue or 2 to exit\n";
        int choice;
        cin>>choice;
        if(choice==1){
            cout<<"Enter coefficient and exponent:\n";
            int coeff,exp;
            cin>>coeff>>exp;
            insert(second,coeff,exp);
        }else if(choice==2){
            break;
        }
    }
    node result=calculate(first,second);
    print(result);

}