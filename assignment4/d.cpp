#include <iostream>
using namespace std;
#include <iostream>
#define mex 100
using namespace std;
struct tree{
    char data;
    tree *left, *right;
    tree(char data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    };
    tree(){
        this->left=nullptr;
        this->right=nullptr;
    }
};
struct stack{
    tree *a[mex];
    int size;
};
void push(stack &st,tree *a){
    if(st.size>=mex) return;
    st.a[st.size]=a;
    st.size++;
}
void pop(stack &st){
    if(st.size==0) return;
    st.size--;
}
tree *top(stack &st){
    if(st.size==0) return 0;
    return st.a[st.size-1];
}
void inorder(tree *root){
    stack st;
    st.size=0;
    tree *temp=root;
    while(temp!=nullptr || st.size!=0){
        while(temp!=nullptr){
            push(st,temp);
            temp=temp->left;
        }
        temp=top(st);
        pop(st);
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void createTree(tree *root){
    cout<<root->data<<" has any left child? ";
    int in;
    cin>>in;
    if(in==1){
        cout<<"Value of the left data: ";
        char c;
        cin>>c;
        root->left=new tree(c);
        createTree(root->left);
    }
    cout<<root->data<<" has any right child? ";
    cin>>in;
    if(in==1){
        cout<<"Value of the right data: ";
        char c;
        cin>>c;
        root->right=new tree(c);
        createTree(root->right);
    }
}
int main(){
    tree *root=new tree();
    cout<<"Root value: ";
    cin>>root->data;
    createTree(root);
    inorder(root);
}