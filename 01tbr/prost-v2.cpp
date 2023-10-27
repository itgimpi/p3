#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
/* odredi da li je broj prost, koren n */

bool prost( ll n ) {
    if ( n == 1 ) return false;
    for ( int i = 2; i * i < n; i++ )
        if ( n % i == 0 )
            return false;
    return true; 
    }
    

    

int main() {
    ll n; cin >> n;
    if ( prost(n) ) cout << "prost";
    else cout << "nije";

    return 0;
}