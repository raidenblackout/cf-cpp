#include <iostream>
#define mex 100
using namespace std;
int graph[mex][mex];
int visited[mex];
int max(int a, int b){
    return (a>b?a:b);
}
bool dfs(int u,int n){
    if(visited[u]==1) return 1;
    if(visited[u]==2) return 0;
    visited[u]=1;
    bool res=0;
    for(int i=0;i<n;i++){
        if(u==i) continue;
        if(graph[u][i]==1){
            res=max(res,dfs(i,n));
        }
    }
    visited[u]=2;
    return res;
}
void createGraph(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<(char)('A'+i)<<"-"<<(char)('A'+j)<<": ";
            int edge;
            cin>>edge;
            if(edge){
                graph[i][j]=1;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    createGraph(n);
    char start;
    cin>>start;
    cout<<(dfs(start-'A',n)==1?"Cycle present":"Cycle not present");
}
