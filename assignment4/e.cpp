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
struct queue{
    tree *arr[mex];
    int size,s,l;
};
void enqueue(queue &q,tree *x){
    if(q.size>0 && q.s==q.l){
        cout<<"QUEUE FULL\n";
        return;
    }
    q.arr[q.l]=x;
    q.l=(q.l+1)%mex;
    q.size++;
}
void dequeue(queue &q){
    if(q.size==0){
        cout<<"QUEUE EMPTY\n";
        return;
    }
    q.s=(q.s+1)%mex;
    q.size--;
}
tree* top(queue &q){
    if(q.size==0){
        return 0;
    }
    return q.arr[q.s];
}
void enqueue2(queue &q,tree *data){
    queue q2;
    q2.size=q2.s=q2.l=0;
    if(q.size>0){
        while(q.size>0){
            enqueue(q2,top(q));
            dequeue(q);
        }
        enqueue(q,data);
        while(q2.size>0){
            enqueue(q,top(q2));
            dequeue(q2);
        }
    }else{
        enqueue(q,data);
    }
}
void inorder(tree *root){
    queue q;
    q.size=q.s=q.l=0;
    tree *temp=root;
    while(temp!=nullptr || q.size!=0){
        while(temp!=nullptr){
            enqueue2(q,temp);
            temp=temp->left;
        }
        temp=top(q);
        dequeue(q);
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