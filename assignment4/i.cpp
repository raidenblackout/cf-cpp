#include <iostream>
using namespace std;
struct tree{
    int data;
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
tree* insert(tree *t, int x){
    if(t==nullptr){
        return new tree(x);
    }
    if(t->data>=x){
        t->left=insert(t->left,x);
    }else{
        t->right=insert(t->right,x);
    }
    return t;
}
tree* search(tree *t, int x){
    if(t==nullptr) return 0;
    if(t->data==x) return t;
    if(t->data>=x) return search(t->left,x);
    return search(t->right,x);
}
int treeminimum(tree *t){
    if(t==nullptr) return 1e9;
    return min(treeminimum(t->left),t->data);
}
void inorder(tree *t){
    if(t==nullptr) return;
    inorder(t->left);
    cout<<t->data<<" ";
    inorder(t->right);
} 
const int mex=100;
int arr[mex];
int l=0;
void generatesuccessors(tree *t){
    if(t==nullptr) return;
    generatesuccessors(t->left);
    arr[l]=t->data;
    l++;
    generatesuccessors(t->right);
}
int successor(tree *t,int n){
    generatesuccessors(t);
    for(int i=0;i<l;i++){
        if(arr[i]==n && i!=l-1){
            return arr[i+1];
        }
    }
    return 0;
}
tree *nextsmallest(tree *t){
    tree *temp=t;
    while(temp!=nullptr && temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}
tree * deletenode(tree *t,int x){
    if(t==nullptr) return t;
    if(x<t->data){
        t->left=deletenode(t->left,x);
    }
    if(x>t->data){
        t->right=deletenode(t->right,x);
    }
    if(x==t->data){
        if(t->left==nullptr && t->right == nullptr){
            return nullptr;
        }
        if(t->left==nullptr){
            tree *change=t->right;
            delete(t);
            return change;
        }
        if(t->right==nullptr){
            tree *change=t->left;
            delete(t);
            return change;
        }
        tree *change=nextsmallest(t->right);
        t->data=change->data;
        t->right=deletenode(t->right,t->data);
    }
    return t;
}
int main(){
    tree *t=nullptr;
    while(1){
        cout<<"Press 1 to insert, 2 to find minimum, 3 to search for a value, 4 inorder traversal, 5 print successor of a node, 6 delete a node\n";
        int x;
        cin>>x;
        int d;
        switch(x){
            case 1:
                cin>>d;
                t=insert(t,d);
                break;
            case 2:
                cout<<treeminimum(t)<<"\n";
                break;
            case 3:
                cin>>d;
                if(search(t,d)){
                    cout<<"Found\n";
                }else{
                    cout<<"Not Found\n";
                }
                break;
            case 4:
                inorder(t);
                cout<<"\n";
                break;
            case 5:
                cin>>d;
                cout<<successor(t,d)<<"\n";
                break;
            case 6:
                cin>>d;
                t=deletenode(t,d);
                break;
        }
    }
}