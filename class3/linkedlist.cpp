#include <iostream>

using namespace std;

struct list{
    int data;
    list *next;
    list *back;
};
typedef struct list node;

void display(node *start){
    node *temp=start;
    // while(temp->next!=nullptr){
    //     //cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int summation(node *start){
    node *temp=start;
    int sum=0;
    while(temp!=nullptr){
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}
void maxmin(node *start){
    node *temp=start;
    int maximum=0,minimum=1e9;
    while(temp!=nullptr){
        maximum=temp->data>maximum?temp->data:maximum;
        minimum=temp->data<minimum?temp->data:minimum;
        temp=temp->next;
    }
    cout<<"Maximum: "<<maximum<<"\nMinimum: "<<minimum<<"\n";
}

bool search(node *start,int value){
    node *temp=start;
    while(temp!=nullptr){
        if(temp->data==value){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
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
    //node *temp=start;
    // int value,n=4;
    // cout<<"Enter 4 values separated by spaces: ";
    // while(n--){
    //     int value;
    //     cin>>value;
    //     insert(&start,value);
    //     // if(start==nullptr){
    //     //     start=new node();
    //     //     start->next=nullptr;
    //     //     start->back=nullptr;
    //     //     start->data=value;
    //     //     temp=start;
    //     //     prev=start;
    //     //     continue;
    //     // }
    //     // while(temp->next!=nullptr){
    //     //     temp=temp->next;
    //     // }
    //     // prev=temp;
    //     // temp->next=new node();
    //     // temp=temp->next;
    //     // temp->data=value;
    //     // temp->next=nullptr;
    //     // temp->back=prev;
    // }
    // cout<<"The nodes are: ";
    // display(start);
    // // cout<<"Total Sum: "<<summation(start)<<"\n";
    // // maxmin(start);
    // // cout<<"Enter the value to search: ";
    // // cin>>value;
    // // cout<<(search(start,value)?"Found\n":"Not Found\n");

}