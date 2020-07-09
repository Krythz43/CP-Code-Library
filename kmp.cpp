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

vi kmpOn3(string s){
    int n = s.length();
    vi pi(n);
    rep(i,n,0){
        cout<<"for index "<<i<<endl;
        for(int k=1;k<=i;k++){
            if(s.substr(0,k) == s.substr(i-k+1,k))pi[i] = k;
            cout <<  "Comparing starting pos " << i-k+1 << " which is " << s.substr(0,k) << " and " << s.substr(i-k+1,k) << endl;
            printarray(pi,pi.size())
        }
        nl;
    }
    return pi;
}

vi kmpOn(string s) {
    int n = s.length();
    vi pi(n);
    rep(i,n,1){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    fastio;
    string s;
    cin>>s;
    vector<int> ans;

    ans = kmpOn3(s);

    printarray(ans,ans.size())
}