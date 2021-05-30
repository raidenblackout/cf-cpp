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
int w,h;
int dp[25][25];
int visited[25][25];
int dfs(vector<vector<char>> &a, int i,int j){
    //cout<<i<<" "<<j<<"\n";
    if(i<0 || j<0 || i==h || j==w){
        return 0;
    }
    if(visited[i][j]) return 0;
    visited[i][j]=1;
    if(a[i][j]=='#'){
        dp[i][j]=0;
        return dp[i][j];
    } 
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=dfs(a,i+1,j)+dfs(a,i,j+1)+dfs(a,i-1,j)+dfs(a,i,j-1)+1;
    return dp[i][j];
}

void run(){
    int t;
    cin>>t;
    int k=1;
    while(t--){
        cout<<"Case "<<k++<<": ";
        memset(dp,-1,sizeof(dp));
        memset(visited,0,sizeof(visited));
        cin>>w>>h;
        vector<vector<char>> a(h,vector<char>(w));
        int x,y;
        fora(i,h){
            fora(j,w){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    x=j,y=i;
                    //cout<<"YES\n";
                }
            }
        }
        cout<<dfs(a,y,x)<<"\n";
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    run();
}
