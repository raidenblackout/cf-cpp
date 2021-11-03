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

struct linkedlist{
    int value;
    linkedlist *next;
};
void insert(linkedlist *head,int value){
    linkedlist *h=head;
    while(h->next!=nullptr){
        //cout<<"YES"<<'\n';
        h=h->next;
    }
    h->next=new linkedlist();
    h=h->next;
    h->value=value;
    h->next=nullptr;
}
void reverse(linkedlist *head){
    cout<<"YES"<<"\n";
    if(head==nullptr){
        return;
    }
    reverse(head->next);
    cout<<"J\n";
    linkedlist *k=head;
    head=head->next;
    head->next=k;
}
void run(){
    linkedlist p;
    p.next=nullptr;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insert(&p,arr[i]);
    }

    reverse(&p);
    cout<<"P\n";
    linkedlist *k=p.next;
    while(k->next!=nullptr){
        cout<<k->value;
        k=k->next;
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    run();
}
