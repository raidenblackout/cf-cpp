/*

Write a program to take as input an array of N names, an array of N ids and an array
of N salaries where the name, id, and salary of the 𝑖
th index belongs to the same
person. Store them in a structure and sort them according to salaries (ascending) and
then by ids (ascending). Print the person in the sorted order.

*/

#include<stdio.h>
#include<string.h>

struct employee{
    char name[50];
    int id;
    int sal;
};

int main(){
    int i, n;
    scanf("%d",&n);
    struct employee e[n];

   for(i=0;i<n;i++){
        fflush(stdin);
        gets(e[i].name);
    }
    for(i=0;i<n;i++){     
       scanf("%d",&e[i].id);
    }
     for(i=0;i<n;i++){
         scanf("%d",&e[i].sal);
    
    }
    int j;
    struct employee temp;
    for (i = 0; i < n; ++i) 
        {
            for (j = i + 1; j < n; ++j) 
            {
                if (e[i].sal> e[j].sal) 
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;                                        
                }
                else if(e[i].sal == e[j].sal) {
                    if(e[i].id> e[j].id){
                         temp = e[i];
                        e[i] = e[j];
                        e[j] = temp;
                    }

                }
            }
        }
        for(i=0;i<n;i++){
            printf("%s %d %d \n",e[i].name, e[i].sal,e[i].id);
        }
}