#include <iostream>
using namespace std;
struct node{
    char c;
    node *next;
};
struct stack{
    node *next;
    int size;
};
void push(char c, stack &st){
    node *temp=st.next;
    st.next=new node();
    st.next->next=temp;
    st.next->c=c;
    st.size++;
}
void pop(stack &st){
    if(st.size==0){
        return;
    }
    node *temp=st.next->next;
    free(st.next);
    st.next=temp;
    st.size--;
}
char top(stack &st){
    if(st.size==0){
        return 0;
    }else{
        return st.next->c;
    }
}
void empty(stack &st){
    while(st.size!=0){
        pop(st);
    }
}


char mapped_opening[]="({[";
char mapped_closing[]=")}]";

int check(string s, int pos,stack &st){
    //balanced or opening bracket overflow
    if(pos==s.size()) return st.size==0;

    for(int i=0;i<3;i++){
        if(s[pos]==mapped_opening[i]){
            push(mapped_opening[i],st);
            return check(s,pos+1,st);
        }
    }

    for(int i=0;i<3;i++){
        if(s[pos]==mapped_closing[i]){
            char x=top(st);
            //stack is empty, closing bracket overflow
            if(x==0) return -1;
            pop(st);
            //unmatched brackets
            if(mapped_opening[i]!=x) return -2;
            return check(s,pos+1,st);
        }
    }
}

int main(){
    stack container;
    container.next=nullptr;
    container.size=0;
    string s;
    cin>>s;
    int result=check(s,0,container);
    if(result==1){
        cout<<"Balanced\n";
    }else if(result==-1){
        cout<<"Closing bracket overflow\n";
    }else if(result==-2){
        cout<<"Unmatched\n";
    }else{
        cout<<"Opening bracket overflow\n";
    }
}