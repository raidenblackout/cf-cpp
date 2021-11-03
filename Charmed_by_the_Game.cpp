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

bool breaks(int a,int b, bool surfer, int n, int surfs){
    if(n==0 && a==0 && b==0) return true;
    if(a==0 && b==0 || surfs==0 || n<0) return false;
    bool k=0,l=0;
    if(surfer){
        if(b!=0 || n!=0){
            k=breaks(a,b-1,!surfer,n-1, surfs-1);
        }
        l=breaks(a-1,b,!surfer,n,surfs-1);
    }else{
        if(a!=0 || n!=0){
            k=breaks(a-1,b,!surfer,n-1,surfs-1);
        }
        l=breaks(a,b-1,!surfer,n,surfs-1);
    }
    return max(k,l);
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int> arr;
        for(int i=0;i<=a+b;i++){
            int l=breaks(a,b,1,i,a+b);
            int m=breaks(a,b,0,i,a+b);
            if(max(l,m)==1){
                arr.push_back(i);
            }
        }
        cout<<arr.size()<<"\n";
        for(auto &x:arr) cout<<x<<" ";
        cout<<"\n";
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
