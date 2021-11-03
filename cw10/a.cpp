#include <iostream>
#define mex 1000
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
    tree arr[mex];
    int size,s,l;
};
void enqueue(queue &q,tree x){
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
tree top(queue &q){
    if(q.size==0){
        return -1;
    }
    return q.arr[q.s];
}
void init(queue &st){
    st.size=0;
    st.l=st.s=0;
}
int level[26];
void levelorder(tree *root){
    queue st;
    init(st);
    enqueue(st,*root);
    level[root->data-'A']=0;
    cout<<"Level: 0 ";

    int prevlev=0;
    while(st.size>0){
        tree node=top(st);
        if(prevlev!=level[node.data-'A']){
            cout<<"\nLevel: "<<level[node.data-'A']<<" ";
            prevlev=level[node.data-'A'];
        }
        cout<<node.data<<" ";
        dequeue(st);
        if(node.left!=nullptr){
            enqueue(st,*node.left);
            level[node.left->data-'A']=level[node.data-'A']+1;
        }
        if(node.right!=nullptr){
            enqueue(st,*node.right);
            level[node.right->data-'A']=level[node.data-'A']+1;
        }
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
    cout<<"Enter root node: ";
    char c;
    cin>>c;
    tree *root=new tree(c);
    createTree(root);
    levelorder(root);
}