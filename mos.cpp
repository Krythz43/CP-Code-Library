#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(lli i=z;i<n;i++)
#define rrep(i,z) for(lli i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define prlliarray(a,n) for(lli i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

const int S = 2e6+5;

lli n,m,k;
lli block_size;

struct Query {
    lli l,r,idx;
    bool operator < (Query other) const{
        return mp(l/block_size,r) < mp(other.l/block_size, other.r);
    }
};

vector<Query> queries;
vi a;

vi ans,pref;
lli cur_ans = 0;
vi occ(S);


void remove(lli idx){
    occ[pref[idx]]--; 
    cur_ans -= occ[pref[idx]^k];
}
void add(lli idx){
    cur_ans += occ[pref[idx]^k];
    occ[pref[idx]]++;    
}

lli get_answer(){
    return cur_ans;
}

void Mos(){
    ans.resize(queries.size());
    sort(all(queries));

    // Intitalize Datastructure here

    pref.resize(n + 1,0);
    rep(i,n + 1,1)pref[i] = (pref[i - 1]^a[i]);

    // End of DS intitalization

    lli cur_l = 0,cur_r = -1;

    for (Query q: queries){

        q.l--;

        // cout<<"solving for "<<q.idx<<endl;
        // cout<<q.l<<" "<<q.r<<endl;

        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        // cout<<cur_l<<" "<<cur_r<<endl;
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        // cout<<cur_l<<" "<<cur_r<<endl;
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        // cout<<cur_l<<" "<<cur_r<<endl;
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        // cout<<cur_l<<" "<<cur_r<<endl;

        ans[q.idx] = get_answer();
    }
}


int main()
{
    fastio;
    cin>>n>>m>>k;
    block_size = sqrt(n) + 1;
    a.resize(n+1,0);
    queries.resize(m);
    rep(i,n + 1,1)cin>>a[i];
    rep(i,m,0){
        cin>>queries[i].l>>queries[i].r;
        queries[i].idx = i;
    }

    Mos();

    for(auto x : ans)cout<<x<<endl;
}