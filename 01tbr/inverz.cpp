#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* dekodiranje */

void f( ll receive, ll secret, ll mod, ll &send ) {
    secret %= mod;
    // Brute Force
    for ( send = 0; send < mod; send++ )
        if ( ( send * secret ) % mod == receive )
            return; 

}
    

    

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll secret, mod; cin >> secret >> mod;
    ll receive;

    while( cin >> receive) {
        ll send;
        f( receive, secret, mod, send );
        cout << send << '\n';

    }
    return 0; }