#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>

#define EPS 1e-100
#define PI  3.1415926535897932384626433832795028841971693993
#define DEG_to_RAD(X)   (X * PI / 180)

using namespace std;

typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int,int>    mii;


struct Point_i{
    int x; int y;
    Point_i(int _x, int _y){ x = _x; y = _y;}
};

struct Point{
    double x,y;
    Point(){ }
    Point(double _x, double _y){
        x = _x; y = _y;
    }
    bool operator < (const Point other){
        if(fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const Point other){
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    struct Point* operator = (const Point *other){
       x = other->x; y = other->y;
       return this;
    }
};

bool areSame(Point_i p1, Point_i p2){
    return p1.x == p2.x && p1.y == p2.y;
}
bool areSame(Point p1, Point p2){
    return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}

double dist(Point p1, Point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

Point rotate(Point p, double theta){
    double rad = DEG_to_RAD(theta);
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

// ax + by + c = 0
struct Line{
    double a,b,c;
};

void PointsToLine(Point p1, Point p2, Line *l){
    if(p1.x == p2.x){
        l->a = 1.0; l->b = 0.0; l->c = -p1.x;
    } else{
        l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
    }
}

bool areParallel(Line l1, Line l2){
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(Line l1, Line l2){
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(Line l1, Line l2,Point *p){
    if(areSame(l1,l2))   return false;
    if(areParallel(l1,l2)) return false;

    p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS){
        p->y = -(l1.a * p->x + l1.c) / l1.b;
    } else{
        p->y = -(l2.a * p->x + l2.c) / l2.b;
    }

    return true;
}

// returs the distance from p to the Line defined by
// two Points A and B ( A and B must bedifferent)
// the closest Point is stored in the 4th parameter (by reference)
double distToLine(Point p, Point A,Point B, Point *c){
    double scale = (double)
        ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
        ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    c->x = A.x + scale * (B.x - A.x);
    c->y = A.y + scale * (B.y - A.y);
    return dist(p, *c);
}

double distToLineSegment(Point p, Point A,Point B, Point *c){
    if( (B.x - A.x) * (p.x - A.x) + (B.y - A.y) * (p.y - A.y) < EPS){
        c->x =  A.x; c->y = A.y;
        return dist(p,A);
    }
    if( (A.x - B.x) * (p.x - B.x) + (A.y - B.y) * (p.y - B.y) < EPS){
        c->x = B.x; c->y = B.y;
        return dist(p,B);
    }
    return distToLine(p,A,B,c);
}

// The cross product of pq,pr
double cross(Point p, Point q, Point r){
    return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

// returns true if Point r is on the same Line as the Line pq
bool collinear(Point p, Point q,Point r){
    return fabs(cross(p,q,r)) < EPS;
}

bool ccw(Point p, Point q, Point r){
    return cross(p,q,r) > 0;
}

struct vec{
    double x, y;
    vec(double _x, double _y){ x = _x, y = _y;}
};

vec toVector(Point p1, Point p2){
    return vec(p2.x - p1.x, p2.y - p1.y);
}

vec scaleVector(vec v, double s){
    return vec(v.x * s, v.y * s);
}

Point translate(Point p, vec v){
    return Point(p.x + v.x, p.y + v.y);
}

bool Point_sort_x(Point a, Point b){
    if( abs(a.x - b.x) < EPS)  return a.y < b.y;
    return (a.x < b.x);
}

int main(){
    double mx,my;int n;
    while(cin >> mx >> my){
        Point p(mx,my);
        cin >> n;
        vector<Point> v;
        for(int i=0;i<=n;i++){
            cin >> mx >> my;
            v.push_back(Point(mx,my));
        }
        
        Point r;
        double min_dist = distToLineSegment(p,v[0],v[1],&r);
        for(int i=1;i<n;i++){
            Point c;
            double dist = distToLineSegment(p,v[i],v[i+1],&c);
            if(dist < min_dist){
                r = c;
                min_dist = dist;
            }
        }
        printf("%.4lf\n%.4lf\n",r.x,r.y);
    }

    return 0;
}
