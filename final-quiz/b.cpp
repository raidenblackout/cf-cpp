#include <iostream>
using namespace std;
struct listNode
{
    int item;
    listNode *next;
    listNode *prev; 
};
struct listNode *head; 
struct listNode *trail; 
int num=0;
listNode *findfromfirst(int n){
    listNode* temp=head;
    for(int i=0;i<n;i++){
        temp=temp->next;
    }
    return temp;
}
listNode *findfromlast(int n){
    listNode* temp=trail;
    for(int i=0;i<n;i++){
        temp=temp->prev;
    }
    return temp;
}
listNode *find(int n){
    if(n<=num/2){
        return findfromfirst(n-1);
    }
    return findfromlast(num-n);
}
int max(int a, int b){
    return (a>b?a:b);
}
int min(int a, int b){
    return (a<b?a:b);
}
void deletes(int N){
    int n=num;
    listNode *arr[num/N+1];
    int k=0;
    for(int i=1;i<=n;i++){
        if(i%N==0){
            arr[k]=find(i);
            k++;
        }
    }
    for(int i=0;i<k;i++){
        if(arr[i]->prev==nullptr){
            head=arr[i]->next;
            if(head!=nullptr){
                head->prev=nullptr;
            }
        }else if(arr[i]->next==nullptr){
            trail=arr[i]->prev;
            if(trail!=nullptr){
                trail->next=nullptr;
            }
        }else{
            arr[i]->prev->next=arr[i]->next;
            arr[i]->next->prev=arr[i]->prev;
        }
        delete(arr[i]);
    }
}
void insert(int n){
    if(num==0){
        head=new listNode();
        head->item=n;
        head->next=head->prev=nullptr;
        trail=head;
        num++;
        return;
    }
    listNode *temp=trail;
    temp->next = new listNode();
    temp->next->prev=temp;
    temp=temp->next;
    temp->item=n;
    trail=temp;
    num++;
}
int findsmallest(int n){
    if(n==0) return 1e9;
    return min(findsmallest(n/10),n%10);
}
void printbefore(){
    listNode *temp=head;
    while(temp){
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
void printafter(){
    listNode *temp=head;
    while(temp){
        int smallest=min(findsmallest(temp->item),temp->item);
        temp->item-=smallest;
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main(){
    while(true){
        cout<<"Press 1 to insert a node:\n";
        int n;
        cin>>n;
        if(n==1){
            int x;
            cout<<"Enter value: ";
            cin>>x;
            insert(x);
        }else break;
    }
    cout<<"Enter a value for N: ";
    int N;
    cin>>N;
    cout<<"Before deletion: ";
    printbefore();
    deletes(N);
    cout<<"After deletion: ";
    printafter();
}