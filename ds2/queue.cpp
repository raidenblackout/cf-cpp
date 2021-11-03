#include <iostream>

using namespace std;

struct queue{
    int f=0,r=0,size=10,data[11];
}q;
void enqueue(int n){
    q.r=(q.r+1)%(q.size+1);
    if(q.r==q.f){
        cout<<"Queue full\n";
        q.r=(q.r+q.size)%(q.size+1);
        return;
    }
    q.data[q.r]=n;
}

void dequeue(){
    if(q.r==q.f){
        cout<<"Queue Empty\n";
        return;
    }
    q.f=(q.f+1)%(q.size+1);
}
void printQueue(){
    for(int i=q.f+1;i!=(q.r+1)%(q.size+1);i=(i+1)%(q.size+1)){
        cout<<q.data[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n=0;
    do{
        cout<<"Enter your choice: ";
        cin>>n;
        switch(n){
            case 1:
                int x;
                cin>>x;
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                break;
            default:
                cout<<"Invalid Input\n";
                break;
        }
    }while(n!=4);
}