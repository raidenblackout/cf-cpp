#include <stdio.h>

int main(){
    freopen("input.txt","r",stdin);
    int x;
    scanf("%d",&x);
    freopen("output.txt","w",stdout);
    if(x%2==0){
        printf("Even\n");
    }else{
        printf("Odd\n");
    }
    
}