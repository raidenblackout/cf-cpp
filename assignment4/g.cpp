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
int max(int a, int b){
    return (a>b?a:b);
}
int maxheight(tree *root){
    if(root==nullptr) return 0;
    int res=maxheight(root->left)+1;
    res=max(res,maxheight(root->right)+1);
    return res;
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
    cout<<maxheight(root)-1<<"\n";
}