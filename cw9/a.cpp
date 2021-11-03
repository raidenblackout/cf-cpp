#include <iostream>
#define mex 1000
using namespace std;
struct stack{
    int a[mex];
    int size;
};
stack st;
void push(int a){
    if(st.size>=mex) return;
    st.a[st.size]=a;
    st.size++;
}
void pop(){
    if(st.size==0) return;
    st.size--;
}
int top(){
    if(st.size==0) return -1;
    return st.a[st.size-1];
}
int graph[mex][mex];
bool visited[mex];
void dfs(int start, int n){
    if(visited[start]) return;
    cout<<(char)(start+'A')<<"\n";
    push(start);
    visited[start]=1;
    while(st.size!=0){
        int u=top();
        pop();
        cout<<(char)('A'+u)<<" ";
        for(int v=0;v<n;v++){
            if(graph[u][v]==1 && !visited[v]){
                visited[v]=1;
                push(v);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<(char)('A'+i)<<"-"<<(char)('A'+j)<<": ";
            int edge;
            cin>>edge;
            if(edge){
                graph[i][j]=graph[j][i]=1;
            }
        }
    }
    char start;
    cin>>start;
    dfs(start-'A',n);

}