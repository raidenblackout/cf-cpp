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
void result(int i,int j, vector<vector<int>> &A, vector<int> &p){
    cout<<i<<" "<<j<<"\n";
    if(i==0 || j==0 || i>j || i==j) return;
    int mid=(i+j)/2;
    result(i,mid,A,p);
    result(mid+1,j,A,p);
    for(int m=i;m<j;m++){
        A[i][j]=min(A[i][m]+A[m+1][j]+p[i-1]*p[m]*p[j],A[i][j]);
    }
}

void run(){
    vector<vector<int>> A(4,vector<int>(4,1e9));
    for(int i=0;i<A.size();i++){
        A[i][i]=0;
    }
    vector<int> p={20,10,30,5};
    result(1,3,A,p);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    //cout<<A[1][3]<<"\n";
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    run();
}
