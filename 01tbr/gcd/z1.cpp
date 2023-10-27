#include <bits/stdc++.h>
using namespace std;
 
/* Euclid */

int gcd1( int a, int b ){
    if ( b == 0 ) return a;
    return gcd1( b, a % b); }

int gcd2( int a, int b ){
    while( b != 0 ){
        int tmp = a % b;
        a = b;
        b = tmp; 

    }


    return a; }    

int main() {
    int a, b, c; cin >> a >> b >> c;



    //cout << gcd1(a, b) << '\n';
    //cout << gcd2(a, b) << '\n';
    cout << __gcd(__gcd(a, b), c) << '\n';

    return 0;
}