#include <bits/stdc++.h>
using namespace std;

/*
xy dec
float, double x, y
fl/dou dist = sqrt(...)

struct { // noname struct
    float x;
    float y; 
} a;          // a is POINT
*/

typedef struct { // tacka u 2D
    double x;
    double y; } point;

typedef struct { // tacka u 3D
    double x, y, z; } point3d;

typedef struct {
    point a, b; }  segment;

typedef struct {
    point a, b, c; }  triangle;

typedef struct { // mnougao, temena su numerisana redom!!!
    int n; // broj Temena
    point pol[100]; } polygone; // najvise 100-ugao

double dist0( point a ) { // rastojanje od koord. pocetka
    return sqrt ( a.x * a.x + a.y * a.y ); }

double dist03d( point3d a ) { // rastojanje od koord. pocetka u 3d
    return sqrt ( a.x * a.x + a.y * a.y + a.z * a.z ); }    

double dist( point a, point b ) { // rast. izmedju 2 tacke
    return sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ); }

double triangle_per( triangle t ) { // obim trougla
    return dist( t.a, t.b ) + dist( t.b, t.c ) + dist( t.c, t.a ); }

double triangle_area( triangle t ) { // povrsina trougla, Heron
    double s = triangle_per(t) / 2.0;
    return sqrt( s * ( s - dist( t.a, t.b ) ) * ( s - dist( t.b, t.c ) ) * ( s - dist( t.c, t.a ) ) ); }

double polygone_per ( polygone p ) { // convex, ordered
    double per = 0.0;
    for ( int i = 0; i < p.n - 1; i++) // neka je n = 6
        per += dist( p.pol[i], p.pol[i+1] ); // 01, 12, 23, 34, 45 
    per += dist( p.pol[p.n-1], p.pol[0] );   // 50
    return per; }

double polygone_area ( polygone p ) { // convex, ordered
    double area = 0.0;

    for ( int i = 0; i < p.n; i++) // neka je n = 6
        area += (p.pol[(i+1)%p.n].y+p.pol[i].y)/2.0*(p.pol[(i+1)%p.n].x-p.pol[i].x);
        // 01, 12, 23, 34, 45, 50 
    
    return abs(area); }

int main() {
    point a, b, c;
    a.x = 1.0; a.y = 1.0;
    b.x = 2.0; b.y = 1.0;
    c.x = 2.0; c.y = 2.0;

    triangle t;
    t.a = a; t.b = b; t.c = c;

    cout << a.x << ' ' << a.y << endl;
    cout << dist0( a ) << endl;
    cout << dist( a, b ) << endl;
    cout << triangle_per( t ) << endl;
    cout << triangle_area( t ) << endl;
    
    





    return 0;
}