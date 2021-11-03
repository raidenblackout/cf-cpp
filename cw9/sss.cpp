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
void heapifybottomtop(int n, vector<int> &arr){
    if(n==0) return;
    int root=(n-1)/2;
    if(arr[root]>arr[n]){
        swap(arr[root],arr[n]);
        heapifybottomtop(root,arr);
    }
}
struct node{
    node *left,*right;
    int data;
    node(int n){
        data=n;
        left=nullptr;
        right=nullptr;
    }
};
class Heap{
    public:
    vector<int> arr;
    Heap(){
    };
    void insert(int data){
        arr.push_back(data);
        heapifybottomtop(arr.size()-1,arr);
    };
};
Heap heap;
void inorder(node *root){
    if(!root) return;
    inorder(root->left);
    heap.insert(root->data);
    inorder(root->right);
}
void print(vector<int> &arr, int level, int sum){
    for(int i=sum;i<sum+(1<<level);i++){
        if(i==arr.size()) return;
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    print(arr,level+1,sum+(1<<level));
}
int visited[100][100];
int piece=1;
int find(vector<vector<int>> &graph, int u, int v,int x,int y){
    if(visited[u][v] || u>=graph.size() || v>=graph[0].size() || u<0 || v<0 || graph[u][v]!=0) return 1e5;

    if(graph[u][v]==piece) return 0;
    visited[u][v]=1;
    int m=1e9;
    int sign1=1;
    for(int i=0;i<2;i++){
        sign1*=-1;
        int sign=1;
        for(int j=0;j<2;j++){
            sign*=-1;
            for(int k=1;k<=2;k++){
                m=min(m,find(graph,u+sign*(k%2+1),v+sign1*((k+1)%2+1),x,y)+1);
            }
        }
    }
    return m;
}


void run(){
    // node *root=new node(5);
    // root->left=new node(3);
    // root->left->left=new node(2);
    // root->left->right=new node(4);
    // root->right=new node(8);
    // root->right->left=new node(6);
    // root->right->right=new node(10);
    // inorder(root);
    // // for(auto &x:heap.arr){
    // //     cout<<x<<" ";
    // // }
    // print(heap.arr,0,0);
    vector<vector<int>> graph(5,vector<int>(4));
    graph[2][1]=0;
    graph[3][0]=1;

    cout<<find(graph,4,2,3,0);

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
