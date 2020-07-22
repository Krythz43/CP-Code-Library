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

/*
    Important pointers:
        1) s = ceil(sqrt(n)) size of each block
        2) Precompute the answer for each block
        3)
*/

const int S = 1e5 + 5;

int n,len;
vlli a(S),b(S);

int main()
{
    fastio;

    int t; cin>>t;

    cin>>n;

    len = (int) sqrt (n + .0) + 1;

    rep(i,n,0)cin>>a[i];
    rep(i,n,0)b[i/len] += a[i];

    while(t--){
        int l,r;
        cin>>l>>r;
        lli sum = 0;
        // for(int i = ;i <= r;){
        //     if(i % len == 0 && i + len - 1 <= r){
        //         sum += b[i / len];
        //         i += len;
        //     }
        //     else{
        //         sum += a[i];
        //         i++;
        //     }
        // }

        /*
            Problems:
                Has too many divison and modulo operators making it slow overall.
        */

        int c_l = l/len, c_r = r/len;
        if(c_l == c_r)rep(i,r + 1,l)sum+=a[i];
        else{
            for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                sum += a[i];
            for (int i=c_l+1; i<=c_r-1; ++i)
                sum += b[i];
            for (int i=c_r*len; i<=r; ++i)
                sum += a[i];
        }

        cout<<sum<endl;
    }
}
