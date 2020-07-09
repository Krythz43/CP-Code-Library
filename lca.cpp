#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e5;

vector <int> height,euler,first,segtree;
vector <int> adj[SIZE];

int n;

void dfs(int x, int h = 1, int p = -1){
    euler.push_back(x);
    height[x] = h;
    for(auto to: adj[x]){
        if(to == p) continue;
        dfs(to,h+1,x);
        euler.push_back(x);
    }
}


int N;

void build(int node, int b, int e) {
    if (b == e) {
        segtree[node] = euler[b];
    } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
    }
}


int query(int node, int b, int e, int L, int R) {
    if (b > R || e < L)
        return -1;
    if (b >= L && e <= R)
        return segtree[node];
    int mid = (b + e) >> 1;
    int left = query(node << 1, b, mid, L, R);
    int right = query(node << 1 | 1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    return height[left] < height[right] ? left : right;
}

void init(){

    for(int i = 0; i <= euler.size() ; i++){
        if(first[euler[i]] != -1)continue;
        first[euler[i]] = i;
    }

    N = euler.size();
    segtree.resize(4*N + 5);
    build(1,0,N-1);
}

int main(){

    cin>>n;
    int x,y;

    height.resize(n+5);
    first.resize(n+1,-1);

    for(int i = 0; i < n-1; i++){
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    dfs(1);
    init();

    for(auto x: first)cout<<x<<" ";
    cout<<endl;
    for(auto x: segtree)cout<<x<<" ";
    cout<<endl;
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        l = first[l];
        r = first[r];
        if(l > r)swap(l,r);
        cout<< query(1,0,N-1,l,r)<<endl;
    }
}