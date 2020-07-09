#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int n,l;
vector<vi> adj;

vi tin,tout;
int timer;
vector<vi> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;

    rep(i,l + 1,1)up[v][i] = up[up[v][i - 1]][i - 1];

    for(auto u: adj[v]){
        if(u != p)dfs(u,v);
    }

    tout = ++timer;
}

bool is_ancestor(int u,int v){
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;

    for(int i = l; i >= 0 ;i--)if(!is_ancestor(up[u][i],v)) u = up[u][i];

    return up[u][0];
}

void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0;

    l = ceil(log2(n));
    up.assign(n,vi (l + 1));
    dfs(root,root);
}

int main()
{
    fastio;
    cin>>n;
    int x,y;

    rep(i,n-1,0){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    preprocess(1);

    int q;
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<"lca of "<<x<<" and "<<y<<" is = "<<lca(x,y)<<endl;
    }
}