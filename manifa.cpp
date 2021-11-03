#include <stdio.h>

struct list{
int data;
list *next;
list *back;
};
typedef struct list node;

void display(node **start)
{
    node *temp;
    temp = *start;
    int t;
    /*
    do{
       printf("%d ", temp->data);
       temp = temp -> next;
   }while(temp!=start);
   */
   while(temp!=start->back){
        printf("%d ", temp->data);
        temp = temp -> next;
   }
   printf("%d ", temp -> data);
}


void sort(node **start)
{
    node *temp, *temp1;
    temp = *start;
    do{
        temp1 = temp -> next;
    while(temp1!=start){
        if(temp -> data > temp1 -> data){
            temp -> next = temp1 -> next;
            temp1 -> next -> back = temp;
            temp1 -> back = temp -> back;
            temp -> back -> next = temp1;
            temp -> back = temp1;
            temp1 -> next = temp;
            printf("oyeoyeo");
            /*
            t = temp -> data;
            temp -> data = temp1 -> data;
            temp1 -> data = t;
            */
        }
        temp1 = temp1 -> next;
    }
    temp = temp -> next;
   }while(temp != start);
   printf("\n");
}
int main()
{
   int ans;
   printf("Do you want to add data? ");
   scanf("%d", &ans);
   while(ans == 1){

    if(start == NULL)
    {
        start = new node();
        printf("Enter data: ");
        scanf("%d", &start->data);
        start -> next = NULL;
        start -> back = NULL;
        prev = start;
    }
    else
    {
        temp = new node();
        printf("Enter data: ");
        scanf("%d", &temp->data);
        prev->next = temp;
        temp->next = prev;
        temp -> back = prev;
        prev = temp;
        start -> back = prev;

    }

    printf("Do you want to add data? ");
    scanf("%d", &ans);
   }
   display(start);
   sort(start);
   display(start);

}