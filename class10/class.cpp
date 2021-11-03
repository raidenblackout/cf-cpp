#include <iostream>
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

void inorder(tree *t){
    if(t==nullptr) return;
    inorder(t->left);
    cout<<t->data<<' ';
    inorder(t->right);
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
    tree root;
    root.left=nullptr;
    root.right=nullptr;
    root.data='R';
    createTree(&root);
    inorder(&root);
}