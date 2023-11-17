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

typedef struct {
    int n;
    point pol[100]; } polygone;

double dist0( point a ) { // rastojanje od koord. pocetka
    return sqrt ( a.x * a.x + a.y * a.y ); }

double dist03d( point3d a ) { // rastojanje od koord. pocetka u 3d
    return sqrt ( a.x * a.x + a.y * a.y + a.z * a.z ); }    

double dist( point a, point b ) { // rast. izmedju 2 tacke
    return sqrt ( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ); }

double triangle_per( triangle t ) {
    return dist( t.a, t.b ) + dist( t.b, t.c ) + dist( t.c, t.a ); }

double triangle_area( triangle t ) {
    double s = triangle_per( t ) / 2.0;
    return sqrt( s * ( s - dist( t.a, t.b ) ) * ( s - dist( t.b, t.c ) ) * ( s - dist( t.c, t.a ) ) ); }

double polygone_per( polygone p ) {
    double per = 0.0;
    for ( int i = 0; i < p.n-1; i++ ) // n = 6, n - 2 = 4
        per += dist(p.pol[i], p.pol[i+1]); // d01 + d12 + d23 + d34 + d45
    per += dist(p.pol[p.n-1], p.pol[0]);   
    return per; }

double polygone_area( polygone p ) { // konvesni, redom
    double area = 0.0;



    for ( int i = 0; i < p.n-1; i++ ) // n = 6, n - 2 = 4
        area += (p.pol[i].y + p.pol[i+1].y)/2.0*(p.pol[i+1].x - p.pol[i].x); 
        // d01 + d12 + d23 + d34 + d45
    area += (p.pol[n-1].y + p.pol[0].y)/2.0*(p.pol[0].x - p.pol[n-1].x);    //d50
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

    polygone p; p.n = 3;
    p.pol[0].x = 1.0; p.pol[0].y = 1.0;
    p.pol[1].x = 2.0; p.pol[1].y = 1.0;
    p.pol[2].x = 2.0; p.pol[2].y = 2.0;
    cout << polygone_per( p ) << endl;

    
    





    return 0;
}