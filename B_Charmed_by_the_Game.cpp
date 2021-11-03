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

bool checker(int a, int b, int n,int k){
    bool result=0;
    int na=n/2,nb=n/2;
    if(n%2==0){
        for(int i=0;i<=k/2;i++){
            int l=k-i;
            fora(j,2){
                if((na-(a-i+l))>=0 && (nb-(b+i-l))>=0){
                    if((a-i)>=0 && (b-l)>=0){
                        result=1;
                    }
                }
                if((na-(a-l+i))>=0 && (nb-(b-i+l))>=0){
                    if((a-l)>=0 && (b-i)>=0){
                        result=1;
                    }
                }
                swap(a,b);
            }
        }
    }else{
        na=nb+1;
        for(int i=0;i<=k/2;i++){
            int l=k-i;
            fora(j,2){
                 if((na-(a-i+l))>=0 && (nb-(b+i-l))>=0){
                    if((a-i)>=0 && (b-l)>=0){
                        result=1;
                    }
                }
                if((na-(a-l+i))>=0 && (nb-(b-i+l))>=0){
                    if((a-l)>=0 && (b-i)>=0){
                        result=1;
                    }
                }
                swap(a,b);
            }
        }
    }
    
    return result;
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int> arr;
        for(int i=0;i<=a+b;i++){
            if(checker(a,b,a+b,i)) arr.pb(i);
        }
        cout<<arr.size()<<'\n';
        for(auto &x:arr){
            cout<<x<<" ";
        }
        cout<<"\n";
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
