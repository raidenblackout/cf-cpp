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
    int n,m;
    cin>>n>>m;
    map<string,int> mp;
    vector<string> s(n);
    fora(i,n){
        cin>>s[i];
        mp[s[i]]++;
    }
    int counter=0;
    string c;
    bool kek=0;
    int pos=-1;
    fora(i,n){
        string p=s[i];
        reverse(p.begin(),p.end());
        if(p==s[i] && mp[p]==1){
            pos=i;
            mp[p]--;
            kek=1;
            continue;
        }
        if(mp[p]>0){
            counter+=m;
            c+=s[i];
            mp[p]--;
            mp[s[i]]--;
        }
    }
    string k;
    if(kek){
        if(m%2==0){
            counter+=m/2;
            counter*=2;
            c+=s[pos].substr(0,m/2);
            //cout<<pos<<'\n';
            k=c;
            reverse(k.begin(),k.end());
            c+=k;
        }else{
            c+=s[pos].substr(0,m/2);
            k=c;
            reverse(k.begin(),k.end());
            c+=s[pos][m/2]+k;
            counter+=m/2;
            counter*=2;
            counter++;
        }
        
    }else{
        k=c;
        reverse(k.begin(),k.end());
        c+=k;
        counter*=2;
    }
    cout<<counter<<"\n"<<c<<"\n";
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
