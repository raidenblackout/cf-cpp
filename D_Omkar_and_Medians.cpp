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

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        fora(i,n) cin>>arr[i];
        multiset<int> pq;
        bool tr=1;
        fora(i,n){
            pq.insert(arr[i]);
            int low=0,high=0;
            int counter=0;
            bool as=0;
            for(auto &x:pq){
                counter++;
                if(x==arr[i] && as==0){
                    low=counter;
                    as=1;
                }
                if(as && x!=arr[i]){
                    high=counter;
                    break;
                }
                if(counter==pq.size()){
                    high=counter-1;
                }
            }
            for(auto &x:pq){
                cout<<x<<" ";
            }
            cout<<"\n";
           // cout<<counter<<'\n';
            int pos=(2*(i+2)-1)/2;
            //cout<<pos<<" \n";
            cout<<i<<" "<<low<<" "<<high<<" "<<pos<<"\n";
            if((pos>=low && pos<=high) || pos-high==1){
                pq.insert(-1e9);
            }else{
                tr=0;
                break;
            }
        }
        if(tr){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
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
