#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
/* odredi broj i zbir svih delioca broja n */

vector<ll> delioci( ll n ) {
    vector<ll>res;
    res.push_back(1);
    if (n > 1) res.push_back(n);
    for ( int i = 2; i < n; i++ )
        if ( n % i == 0 ) {
            res.push_back(i);
        }
    return res; }

int main() {
    ll n; cin >> n;
    vector<ll>d = delioci(n);
    cout << d.size() << '\n';
    for ( int i = 0; i < d.size(); i++ ) cout << d[i] << ' ';

    return 0;
}