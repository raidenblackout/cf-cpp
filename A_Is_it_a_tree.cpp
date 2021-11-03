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
int visited[10000+5];
bool dfs(vector<vector<int>>&graph,int u,int p){
    if(visited[u]){
        if(visited[u]!=p) return true;
        return false;
    }
    visited[u]=p;
    bool res=true;
    for(auto &x:graph[u]){
        res=min(dfs(graph,x,p),res);
    }
    return res;
}
int find(vector<int> &graph,int u){
    if(graph[u]==u) return u;
    int p=find(graph,graph[u]);
    graph[u]=p;
    return p;
}
void join(vector<int> &graph,int u, int v){
    int p=find(graph,u);
    int k=find(graph,v);
    if(p!=v){
        graph[v]=p;
    }
}
void run(){
    int n,m;
    cin>>n>>m;
    vector<int> heads(n);
    fora(i,n) heads[i]=i;
    bool k=1;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(find(heads,v)==find(heads,u)){
            k=false;
        }
        join(heads,u-1,v-1);
    }
    if(k){
        int p=find(heads,0);
        fora(i,n){
            if(find(heads,i)!=p){
                k=0;
                break;
            }
        }
        cout<<(k?"YES\n":"NO\n");
    }else{
        cout<<"NO\n";
    }

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
