#include <bits/stdc++.h>
using namespace std;

#define S 100000
#define pb push_back

//tin denotes entry time for node v
//low is minimum of tin[v] 
vector<int> a[S];
vector<bool> vis(S,false);
vector<int> tin(S),low(S);
int timer=0;
int n,m;

void IS_BRIDGE(int x,int y){
    cout<<"("<<x<<","<<y<<") is a bridge"<<endl;
}

void dfs(int v,int p=-1){
    vis[v]=true;
    tin[v]=low[v]=timer++;
    for(int to:a[v]){
        if(to==p)continue;
        if(vis[to])low[v]=min(low[v],tin[to]);
        else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>tin[v])IS_BRIDGE(v,to);
        }
    }
}

int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<" tin:"<<tin[i]<<" low:"<<low[i]<<endl;
    }

}