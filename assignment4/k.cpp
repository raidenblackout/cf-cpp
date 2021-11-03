#include <iostream>
#define mex 100
using namespace std;
struct node{
    node *next;
    string data;
    int value;
    node(string data,int value){
        this->data=data;
        this->next=nullptr;
        this->value=value;
    }
};
struct map{
    node *arr[mex];
    int p,counter=0;
    map(){
        for(int i=0;i<mex;i++) this->arr[i]=nullptr;
    }
};
int pow(int a, int b){
    if(b==0) return 1;
    if(b%2==0){
        int x=pow(a,b/2);
        return x*x;
    }else{
        int x=pow(a,b/2);
        return x*x*a;
    }
}
int hasher(map &mp,string s){
    int res=0;
    for(int i=0;i<s.size();i++){
        res+=(pow(mp.p,i)*s[i])%mex;
    }
    return res%mex;
}
int insert(map &mp, string k){
    int m=hasher(mp,k);
    node *root=mp.arr[m];
    node *prev=nullptr;
    if(mp.arr[m]==nullptr){
        mp.arr[m]=new node(k,mp.counter++);
        return mp.counter-1;
    }
    while(root){
        if(root->data==k){
            return -1;
        }
        prev=root;
        root=root->next;
    }
    prev->next=new node(k,mp.counter++);
    return mp.counter-1;
}
int find(map &mp, string k){
    int m=hasher(mp,k);
    node *root=mp.arr[m];
    if(mp.arr[m]==nullptr){
        return -1;
    }
    while(root){
        if(root->data==k){
            return root->value;
        }
        root=root->next;
    }
}
int main(){
    map l;
    l.p=5;
    for(int i=0;i<mex;i++){
        l.arr[i]=nullptr;
    }
    cout<<insert(l,"latin");
    cout<<"\n"<<insert(l,"latin");
    cout<<"\n"<<insert(l,"robin");
    insert(l,"haha");
    cout<<"\n"<<find(l,"latin")<<" "<<find(l,"robin")<<" "<<find(l,"haha");
    cout<<"\n"<<(nullptr==NULL)<<"\n";
}