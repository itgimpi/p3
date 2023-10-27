#include <bits/stdc++.h>
using namespace std;
 
/* odredi broj i zbir prostih, n koren n */

/*bool prost( int n ) {
    if ( n == 1 ) return false;
    for ( int i = 2; i * i <= n; i++ )
        if ( n % i == 0 )
            return false;
    return true;      } */

void sito( vector<bool>&prost, int n) {
    prost.resize(n+1, true);
    prost[0] = prost[1] = false;
    for ( int i = 2; i*i <= n; i++ )
        if ( prost[i] )
            for ( int ii = i*i; ii <= n; ii+=i )
                prost[ii] = false;

}

void interval( int a, int b, int &br, int &zb ) {
    vector<bool>prost;
    sito(prost, b);

    br = zb = 0;
    for ( int i = a; i <= b; i++ )
        if ( prost[i] ) {
            //cout << i << '\n';
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