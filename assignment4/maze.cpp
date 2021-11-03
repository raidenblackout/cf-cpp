#include <iostream>
#define mex 100
using namespace std;
struct stack{
    char a[mex];
    int size;
};
void push(stack &st,char a){
    if(st.size>=mex) return;
    st.a[st.size]=a;
    st.size++;
}
void pop(stack &st){
    if(st.size==0) return;
    st.size--;
}
char top(stack &st){
    if(st.size==0) return -1;
    return st.a[st.size-1];
}
string graph[mex];
int visited[mex][mex];
char blades[]="ABC";
char vampires[]="MNO";
int res(int x, int y, stack &st){
    if(graph[y][x]=='E'){
        return 1;
    }
    if(graph[y][x]=='-' || graph[y][x]=='X') return 0;
    if(visited[y][x]) return 0;
    visited[y][x]=1;
    for(int i=0;i<3;i++){
        if(graph[y][x]==blades[i]){
            cout<<"Blade found: "<<blades[i]<<"\n";
            push(st,graph[y][x]);
            continue;
        }
    }
    char last=top(st);
    for(int i=0;i<3;i++){
        if(graph[y][x]==vampires[i]){
            if(blades[i]==last){
                cout<<"Enemy "<<vampires[i]<<" is killed\n";
                pop(st);
            }else{
                cout<<"You are killed by enemy "<<vampires[i]<<"\n";
                return 0;
            }
            continue;
        }
    }
    int result=res(x+1,y,st);
    result=max(result,res(x-1,y,st));
    result=max(result,res(x,y+1,st));
    result=max(result,res(x,y-1,st));
    visited[y][x]=0;
    return result;
}
int main(){
    int n,m;
    cin>>n>>m;
    int startx,starty;
    for(int i=0;i<n;i++){
        cin>>graph[i];
        for(int j=0;j<m;j++){
            if(graph[i][j]=='S'){
                startx=j;
                starty=i;
            }
        }
    }
    stack st;
    cout<<(res(startx,starty,st)==1?"Game Complete....":"");
}