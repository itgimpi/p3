#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* bezuovi koef. */
/* extended euclid */

void bezu(ll a, ll b, ll &s, ll &t) {
    ll r0 = a, r1 = b;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;

    while ( r1 > 0 ) {
        ll q = r0 / r1;
        ll tmp;

        tmp = r0;
        r0 = r1;
        r1 = tmp - q * r1;

        tmp = s0;
        s0 = s1;
        s1 = tmp - q * s1;

        tmp = t0;
        t0 = t1;
        t1 = tmp - q * t1;
    }
    s = s0; t = t0;

}
  
int main() {
    ll a, b, s, t; cin >> a >> b;
    bezu(a, b, s, t);
    cout << s << ' ' << t;
    return 0; }