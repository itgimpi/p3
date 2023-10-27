#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* dekodiranje */

ll bezu( ll mod, ll secret, ll &s, ll &t){
    ll r0 = mod, r1 = secret;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;

    while ( r1 > 0 ) {
        ll q = r0 / r1; // q je isti za sva tri dela
        ll tmp;

        tmp = r0;
        r0 = r1;
        r1 = tmp - q * r1;

        tmp = s0;
        s0 = s1;
        s1 = tmp - q * s1;

        tmp = t0;
        t0 = t1;
        t1 = tmp - q * t1;     } 
    s = s0; t = t0;  
    return r0; }

bool inverz( ll secret, ll mod, ll &t ) {
    
    ll s;
    ll r = bezu( mod, secret, s, t);

    return r == 1;
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