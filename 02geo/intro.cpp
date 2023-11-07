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

double dist0( point a ) { // rastojanje od koord. pocetka
    return sqrt ( a.x * a.x + a.y * a.y ); }

double dist03d( point3d a ) { // rastojanje od koord. pocetka u 3d
    return sqrt ( a.x * a.x + a.y * a.y + a.z * a.z ); }    

double dist( point a, point b ) { // rast. izmedju 2 tacke
    return sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ); }

double triangle_per( triangle t ) {
    return dist( t.a, t.b ) + dist( t.b, t.c ) + dist( t.c, t.a ); }

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
    
    





    return 0;
}