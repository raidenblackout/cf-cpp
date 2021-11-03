#include <bits/stdc++.h>
#define mex 1000
using namespace std;
int graph[mex][mex];
int visited[mex][mex];
int find(int n, int u, int v,int piece){
    if(visited[u][v] || u>=n || v>=n || u<0 || v<0|| graph[u][v]==-1) return 1e5;
    if(graph[u][v]==piece) return 0;
    visited[u][v]=1;
    int m=1e9;
    int sign1=1;
    for(int i=0;i<2;i++){
        sign1*=-1;
        int sign=1;
        for(int j=0;j<2;j++){
            sign*=-1;
            for(int k=1;k<=2;k++){
                m=min(m,find(n,u+sign*(k%2+1),v+sign1*((k+1)%2+1),piece)+1);
            }
        }
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    //opponent pieces
    string s[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y>>s[i];
        graph[y][x]=i+1;
    }
    //own pieces
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        graph[y][x]=-1;
    }
    int len=max(k,n);
    //position of knight
    int numofknights;
    cin>>numofknights;
    int arr[n];
    memset(arr,1,sizeof(arr));
    while(numofknights--){
        int posy,posx;
        cin>>posx>>posy;
        graph[posy][posx]=0;
        for(int i=1;i<=n;i++){
            memset(visited,0,sizeof(visited));
            arr[i-1]=min(arr[i-1],find(5,posy,posx,i));
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<": "<<arr[i]<<endl;
    }

}