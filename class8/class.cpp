#include <iostream>

using namespace std;

int main(){
    char vertex[26];
    for(int i=0;i<26;i++){
        vertex[i]='A'+i;
    }
    cout<<"Number of vertices: ";
    int n;
    cin>>n;
    int graph[n][n];
    for(int i=0;i<n;i++){
        graph[i][i]=0;
        for(int j=i+1;j<n;j++){
            cout<<vertex[i]<<"-"<<vertex[j]<<" exist? ";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
    cout<<"Enter the vertex: ";
    char c;
    cin>>c;
    cout<<vertex[c-'A']<<": ";
    for(int j=0;j<n;j++){
        if(graph[c-'A'][j]) cout<<vertex[j]<<" ";
    }
    cout<<"\n";
}
