#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/
int dfs(vector<vector<int>> &graph, int u, vector<int> &visited,int counter,int m,vector<int> &cats){
    if(cats[u]==1 && counter+1>m) return 0;
    if(graph[u].size()==0 && u!=0) return 1;
    int res=0;
    if(cats[u]==1){
        fora(i,graph[u].size()){
            res+=dfs(graph,graph[u][i],visited,counter+1,m,cats);
        }
    }else{
        fora(i,graph[u].size()){
            res+=dfs(graph,graph[u][i],visited,0,m,cats);
        }
    }
    return res;
}


void run(){
    int n,m;
    cin>>n>>m;
    vector<int> cats(n,0);
    vector<vector<int>> edges(n);
    vector<int> visited(n);
    fora(i,n){
        cin>>cats[i];
    }
    fora(i,n-1){
        int x,y;
        cin>>x>>y;
        edges[x-1].pb(y-1);
    }
    cout<<dfs(edges,0,visited,0,m,cats)<<"\n";
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
