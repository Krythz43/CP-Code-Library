#include <bits/stdc++.h>
using namespace std;

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

struct point3d {
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) {x += t.x;y += t.y;z += t.z;return *this;}
    point3d& operator-=(const point3d &t) {x -= t.x;y -= t.y;z -= t.z;return *this;}
    point3d& operator*=(ftype t) {x *= t;y *= t;z *= t;return *this;}
    point3d& operator/=(ftype t) {x /= t;y /= t;z /= t;return *this;}
    point3d operator+(const point3d &t) const {return point3d(*this) += t;}
    point3d operator-(const point3d &t) const {return point3d(*this) -= t;}
    point3d operator*(ftype t) const {return point3d(*this) *= t;}
    point3d operator/(ftype t) const {return point3d(*this) /= t;}
};
point3d operator*(ftype a, point3d b) {return b * a;}

ftype dot(point2d a, point2d b) {return a.x * b.x + a.y * b.y;}
ftype dot(point3d a, point3d b) {return a.x * b.x + a.y * b.y + a.z * b.z;}

ftype norm(point2d a) {return dot(a, a);}

long double abs(point2d a) {return sqrt(norm(a));}
long double proj(point2d a, point2d b) {return dot(a, b) / abs(b);}
long double angle(point2d a, point2d b) {return acos(dot(a, b) / abs(a) / abs(b));}

point3d cross(point3d a, point3d b) {return point3d(a.y * b.z - a.z * b.y,a.z * b.x - a.x * b.z,a.x * b.y - a.y * b.x);}
ftype triple(point3d a, point3d b, point3d c) {return dot(a, cross(b, c));}
ftype cross(point2d a, point2d b) {return a.x * b.y - a.y * b.x;}

int main(){
    point2d a;
    cout<<a.x<<" "<<a.y<<endl;
    point2d b(5,3);
    cout<<b.x<<" "<<b.y<<endl;    
    point2d c(5,3);
    b = 5 * b;
    cout<<b.x<<" "<<b.y<<endl;    
}