#include <stdio.h>

struct stack{
    char a[100];
    int top;
    int size;
};
struct stack stack1;

struct Tree
{
    char data;
    Tree *left, *right;
};
typedef struct Tree node;

bool Is_full(){
    if(stack1.top+1 == stack1.size){
        return true; //full stack
    }
    else
        return false; //not full
}

bool Is_empty(){
    if(stack1.top == -1){
        return true; //empty stack
    }
    else
        return false; //not empty
}

void push(char item){
    Is_full();
    if(Is_full() == false){
        stack1.top++;
        stack1.a[stack1.top] = item;
    }
    else{
        printf("Stack Overflow\n");
    }
}

void pop(){
    Is_empty();
    if(Is_empty() == false){
        stack1.a[stack1.top] = 0;
        stack1.top--;
    }
    else{
        printf("Stack Underflow\n");
    }
}

char Top_up(){
    return stack1.a[stack1.top];
}

void createTree(node *root)
{
    int ans;

    //Left part

    printf("%c has any left child? ", root->data);
    scanf("%d", &ans);
    if(ans == 1)
    {
        root->left = new node;
        printf("Enter left data of %c: ", root->data);
        scanf("\n%c", &root->left->data);
        createTree(root->left);
    }
    else
    {
        root->left = NULL;
    }

    //Right part

    printf("%c has any right child? ", root->data);
    scanf("%d", &ans);
    if(ans == 1)
    {
        root->right = new node;
        printf("Enter right data of %c: ", root->data);
        scanf("\n%c", &root->right->data);
        createTree(root->right);
    }
    else
    {
        root->right = NULL;
    }
}

void inorder(node *root)
{
    node *temp = new node();
    int i = 0;
    while(i == 0)
    {
        if(root != NULL){
            push(root->data);
            root = root->left;
        }
        else
        {
            if(Is_empty() == false)
            {
                temp->data = Top_up();
                pop();
                printf("%c ", temp->data);
                root = root->right;
            }
            else
            {
                i = 1;
            }
        }
    }

}

int main()
{

    stack1.size = 5;
    stack1.top = -1;

    node *root = new node();
    printf("Enter root data: ");
    scanf("\n%c", &root->data);

    createTree(root);
    inorder(root);

}