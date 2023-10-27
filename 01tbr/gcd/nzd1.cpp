#include <bits/stdc++.h>
using namespace std;
 
int main() {

    int a, b, c; cin >> a >> b >> c;

    int res = __gcd( a, b );
    res = gcd( res, c );
    cout << res;


    return 0; }