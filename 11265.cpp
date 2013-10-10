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
#define RAD_to_DEG(X)   (X / PI * 180)

#define CIR_INSIDE  0
#define CIR_BORDER  1
#define CIR_OUTSIDE 2

#define TRI_NONE    0
#define TRI_ACUTE   1
#define TRI_RIGHT   2
#define TRI_OBTUSE  3

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
    bool operator < (const Point other) const{
        if(fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const Point other) const{
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

   struct Point* operator = (const Point *other){
       x = other->x; y = other->y;
       return this;
    }
};

struct Circle{
    Point c;
    double r;
    Circle(Point _c, double _r){
        c = _c; r = _r;
    }

    Circle* operator = (const Circle *oth){
        c = oth->c; r = oth->r;
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

    const bool operator<(Line x) const{
        if(abs(a - x.a) > EPS)  return a < x.a;
        if(abs(b - x.b) > EPS)  return b < x.b;
        if(abs(c - x.c) > EPS)  return c < x.c;
        return false;   // when it's equal
    }
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
double crossProduct(Point p, Point q, Point r){
    return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

// returns true if Point r is on the same Line as the Line pq
bool colinear(Point p, Point q,Point r){
    return fabs(crossProduct(p,q,r)) < EPS;
}

bool ccw(Point p, Point q, Point r){
    return crossProduct(p,q,r) > 0;
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
    if( fabs(a.x - b.x) < EPS)  return a.y < b.y;
    return (a.x < b.x);
}


        /* Circles */
// int version
int inCircle(Point_i p, Point_i c, int r){
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq= r * r;
    return Euc < rSq ? CIR_INSIDE : Euc == rSq ? CIR_BORDER : CIR_OUTSIDE;
}

// float version
int inCircle(Point p, Point c, int r){
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq= r * r;
    return (Euc - rSq < EPS) ? CIR_BORDER : Euc < rSq ? CIR_INSIDE : CIR_OUTSIDE;
}

bool circle2PtsRad(Point p1, Point p2, double r, Point *c){
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if(det < 0) return false;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}


        /* Triangle */
// Find the trigangle type based on the arr of points given
int findTriangleType(Point arr[]){
    double res = crossProduct(arr[0],arr[1],arr[2]);
    if(fabs(res) < EPS)  return TRI_RIGHT;
    else if(res < 0) return TRI_OBTUSE;

    res = crossProduct(arr[1],arr[0],arr[2]);
    if(res < EPS){
        swap(arr[0],arr[1]);
        if(fabs(res) < EPS)    return TRI_RIGHT;
        return TRI_OBTUSE;
    }

    res = crossProduct(arr[2],arr[0],arr[1]);
    if(res < EPS){
        swap(arr[0],arr[1]);
        if(fabs(res) < EPS)  return TRI_RIGHT;
        return TRI_OBTUSE;
    }
    return TRI_ACUTE;
}

double perimeter(vector<Point> P){
    double result = 0.0;
    for(int i=0;i<P.size()-1;i++){
        result += dist(P[i],P[i+1]);
    }
    return result;
}

double polygonArea(vector<Point> P){
    double result = 0, x1, y1, x2, y2;
    for(int i=0;i<P.size()-1;i++){
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

bool isConvex(vector<Point> P){
    int sz = (int) P.size();
    if(sz < 3)  return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for(int i=1; i<(int)P.size();i++){
        if(ccw(P[i],P[(i+1)%sz],P[(i+2)%sz]) != isLeft) return false;
    }
    return true;
}

double angle(Point a, Point b, Point c){
    double ux = b.x - a.x, uy = b.y - a.y;
    double vx = c.x - a.x, vy = c.y - a.y;
    return acos( (ux * vx + uy*vy) / sqrt((ux*ux + uy*uy) * ( vx*vx + vy*vy)));
}

bool inPolygon(Point p, vector<Point> P){
    if(P.size() == 0) return false;
    double sum = 0;
    for(int i=0;i<P.size() -1; i++){
        if(crossProduct(p,P[i],P[i+1]) < 0)    sum -= angle(p,P[i],P[i+1]);
        else    sum += angle(p,P[i],P[i+1]);
    }
    return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}

Point lineIntersectSeg(Point p, Point q, Point A, Point B){
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a*p.x + b*p.y + c);
    double v = fabs(a*q.x + b*q.y + c);
    return Point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<Point> cutPolygon(Point a, Point b, vector<Point> Q) {
    vector<Point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = crossProduct(a, b, Q[i]), left2 = 0.0;
        if (i != (int)Q.size() - 1) left2 = crossProduct(a, b, Q[i + 1]);
        if (left1 > -EPS) P.push_back(Q[i]);
        if (left1 * left2 < -EPS)
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
    }
    if (P.empty()) return P;
    if (fabs(P.back().x - P.front().x) > EPS ||
        fabs(P.back().y - P.front().y) > EPS)
        P.push_back(P.front());
    return P; }

Point pivot(0, 0);
bool angle_cmp(Point a, Point b) { // angle-sorting function
    if (colinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b); // which one is closer?
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }

vector<Point> CH(vector<Point> P) {
    int i, N = (int)P.size();
    if (N <= 3) return P; // special case, the CH is P itself
    
    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < N; i++)
        if (P[i].y  < P[P0].y ||
            (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    // swap selected vertex with P[0]
    Point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    
    // second, sort points by angle w.r.t. P0, skipping P[0]
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angle_cmp);
    
    // third, the ccw tests
    Point prev(0, 0), now(0, 0);
    stack<Point> S; S.push(P[N - 1]); S.push(P[0]); // initial
    i = 1; // and start checking the rest
    while (i < N) { // note: N must be >= 3 for this method to work
        now = S.top();
        S.pop(); prev = S.top(); S.push(now); // get 2nd from top
        if (ccw(prev, now, P[i])) S.push(P[i++]); // left turn, ACC
        else S.pop(); // otherwise, pop until we have a left turn
    }
    
    vector<Point> ConvexHull; // from stack back to vector
    while (!S.empty()) { ConvexHull.push_back(S.top()); S.pop(); }
    return ConvexHull; 
}

int main(){
    int N,CC = 1;
    double W,H,x,y;

    while(cin >> N >> W >> H >> x >> y && N){
        Point sp(x,y);
        vector<Point> vc;
        vc.push_back(Point(0,0));
        vc.push_back(Point(W,0));
        vc.push_back(Point(W,H));
        vc.push_back(Point(0,H));
        vc.push_back(Point(0,0));

        for(int i=0;i<N;i++){
            cin >> x >> y;Point ps(x,y);
            cin >> x >> y;Point pe(x,y);
            if(ccw(ps,pe,sp))   vc = cutPolygon(ps,pe,vc);
            else                vc = cutPolygon(pe,ps,vc);
        }
        printf("Case #%d: %.3lf\n",CC++,polygonArea(vc));
    }
    
    return 0;
}
