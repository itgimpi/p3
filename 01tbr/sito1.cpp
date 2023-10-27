#include <bits/stdc++.h>
using namespace std;
 
/* odredi broj i zbir prostih, n koren n */

bool prost( int n ) {
    if ( n == 1 ) return false;
    for ( int i = 2; i * i <= n; i++ )
        if ( n % i == 0 )
            return false;
    return true; 
    }

void interval( int a, int b, int &br, int &zb ) {

    br = zb = 0;
    for ( int i = a; i <= b; i++ )
        if ( prost( i ) ) {
            cout << i << '\n';
            br++;
            zb = ( zb + i ) % 1000000; }


}
    

    

int main() {
    int a, b; cin >> a >> b;
    int br, zb;

    interval(a, b, br, zb); // 2 ulaza, 2 za menjanje
    cout << br << ' ' << zb;

    return 0;
}