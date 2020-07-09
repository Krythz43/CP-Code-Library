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
    CONVEX HULL ALGO:

    1) Find the leftmost bottommost point (A)
    2) Find the rightmost topmost point (B)
    3) The line AB divides points into two sets. A and B belong to both sets.

        Upper set:
        (i) Sort all points by x coordinate
        (ii) For each point, check if the current point is the last point or
             if the orientation is cw, if so add it to the set.
        (iii)Check the last before and last point line and last and current
             point line orientation, if cw add it to the set. 
                                     else remove the last point. add current point

        Lower set:
        (i) Same logic but countclockwise instead.

*/

typedef long long int ftype;

struct point2d{
    ftype x,y;
    point2d(){}
    point2d(ftype x,ftype y):x(x),y(y){}

    point2d & operator += (const point2d &t){x += t.x;y += t.y;return * this;}
    point2d & operator -= (const point2d &t){x -= t.x;y -= t.y;return * this;}
    point2d& operator*=(ftype t) {x *= t;y *= t;return *this;}
    point2d& operator/=(ftype t) {x /= t;y /= t;return *this;}
    point2d operator+(const point2d &t) const {return point2d(*this) += t;}
    point2d operator-(const point2d &t) const {return point2d(*this) -= t;}
    point2d operator*(ftype t) const {return point2d(*this) *= t;}
    point2d operator/(ftype t) const {return point2d(*this) /= t;}
};
point2d operator*(ftype a, point2d b) {return b * a;}

ftype cross(point2d a, point2d b) {return a.x * b.y - a.y * b.x;}

bool comp(point2d a,point2d b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(point2d a, point2d b, point2d c){
    return cross(b - a, c - b) < 0; 
}

bool ccw(point2d a, point2d b, point2d c){
    return cross(b - a, c - b) > 0; 
}



int n;
vector<point2d> a;

void convex_hull(){
    if(a.size() == 1)return;
    sort(all(a),comp);

    point2d p1 = a[0],p2 = a.back();

    if(p1.x == p2.x && p1.y == p2.y){
        a.clear();
        a.pb(p1);
        return;
    }

    vector<point2d> up,down;
    up.pb(p1);
    down.pb(p1);

    rep(i,n,0){
        if(i == n-1 || cw(p1,a[i],p2)){
            while(up.size() >= 2 && !cw(up[up.size() - 2], up.back(),a[i]))
                up.pop_back();
            up.pb(a[i]);
        }

        if(i == n-1 || ccw(p1,a[i],p2)){
            while(down.size() >= 2 && !ccw(down[down.size() - 2], down.back(),a[i]))
                down.pop_back();
            down.pb(a[i]);
        }
    }

    a.clear();

    rep(i,down.size(),0)a.pb(down[i]);
    for(int i = up.size()-2 ; i > 0; i--)a.pb(up[i]);
}


int main(){
    fastio;
    while(cin>>n){
        if(n == 0)break;
        a.resize(n);
        int x, y;
        rep(i,n,0){
            cin>>x>>y;
            a[i] = point2d(x,y);
        }
        convex_hull();

        cout<<a.size()<<endl;
        rep(i,a.size(),0)cout<<a[i].x<<" "<<a[i].y<<endl;
    }
}