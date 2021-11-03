#include <bits/stdc++.h>
#define mex 1000
using namespace std;
int graph[mex][mex];
int visited[mex][mex];
void find(int x,int y){
    memset(visited,1,sizeof(visited));
    visited[y][x]=0;
    int m=1e9;
    int sign1=1;
        stack<pair<int,int>> st;
        st.push({x,y});
        while(!st.empty()){
            int u=st.top().first;
            int v=st.top().second;
            st.pop();
            for(int i=0;i<2;i++){
                sign1*=-1;
                int sign=1;
                for(int j=0;j<2;j++){
                    sign*=-1;
                    for(int k=1;k<=2;k++){
                        int nx=u+sign*(k%2+1);
                        int ny=v+sign1*((k+1)%2+1);
                        if(ny<0 || nx<0 || ny>=12 || nx>=12) continue;
                        if(graph[ny][nx]<0){
                            continue;
                        }
                        if(visited[ny][nx]>visited[v][u]+1){
                            visited[ny][nx]=visited[v][u]+1;
                            st.push({nx,ny});
                        }
                    }
                }
            }
        }
    //}
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
    int p;
    cin>>p;
    while(p--){
        int x,y;
        cin>>x>>y;
        graph[y][x]=0;
        find(x,y);
        cout<<visited[][];
    }
    //position of knight
    // int numofknights;
    // cin>>numofknights;
    // int arr[n];
    // memset(arr,1,sizeof(arr));
    // // while(numofknights--){
    // //     int posy,posx;
    // //     cin>>posx>>posy;
    // //     graph[posy][posx]=0;
    // //     for(int i=1;i<=n;i++){
    // //         memset(visited,1,sizeof(visited));
    // //         visited[posy][posx]=0;
    // //         arr[i-1]=min(arr[i-1],find(20,posy,posx,posy,posx,i));
    // //     }
    // // }
    // for(int i=0;i<n;i++){
    //     cout<<s[i]<<": "<<arr[i]<<endl;
    // }

}