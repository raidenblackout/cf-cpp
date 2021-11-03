#include <iostream>
#define mex 1000
using namespace std;
int graph[mex][mex];
int visited[mex];
void dfs(int u, int n){
    if(visited[u]) return;
    visited[u]=1;
    cout<<(char)(u+'A')<<" ";
    for(int v=0;v<n;v++){
        if(graph[u][v]==1) dfs(v,n);
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