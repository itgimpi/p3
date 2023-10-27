#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* dekodiranje */

void inverz( ll secret, ll mod, ll &invsecret ) {
    secret %= mod;

    // Brute Force 2

    for ( invsecret  = 0; invsecret < mod; invsecret++ )
        if ( (secret * invsecret) % mod == 1  )
            return; 

}
    

    

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll secret, mod; cin >> secret >> mod;
    ll invsecret;

    inverz( secret, mod, invsecret );

    ll receive;

    while( cin >> receive) {

        cout << ( receive * invsecret ) % mod  << '\n';

    }
    return 0; }