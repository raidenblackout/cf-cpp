#include <iostream>

using namespace std;

struct stack{
    int a[100];
    int top;
    int size;
}stack1;

bool is_full(){
    if(stack1.top+1==stack1.size){
        return 1;
    }
    return 0;
}
bool Is_empty(){
    if(stack1.top==-1){
        return 1;
    }
    return 0;
}
int top_up(){
    if(!Is_empty()){
        return stack1.a[stack1.top];
    }
    return -1;
}
void push(int value){
    if(!is_full()){
        stack1.top++;
        stack1.a[stack1.top]=value;
    }else{
        cout<<"Stack Overflow\n";
    }
}
void pop(){
    if(!Is_empty()){
        stack1.top--;
    }else{
        cout<<"Stack Underflow\n";
    }
}
void init(){
    stack1.top=-1;
    stack1.size=100;
}
void print_stack(){
    for(int i=0;i<=stack1.top;i++){
        cout<<stack1.a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    init();
    bool exit=0;
    do{
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                
        }
    }while(!exit);
}