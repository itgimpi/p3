#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull a, n, m; cin >> a >> n >> m;

    a %= m;
    ull res = 1;
    for ( ull i = 0; i < n; i++ )
        res = res * a % m;
    cout << res % m;
}