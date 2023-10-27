#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull fib ( ull n ) {
    // Base Case
    if ( n == 0 || n == 1 ) return 1;
    return fib( n - 1 ) + fib( n - 2 ); }

int main() {
    ull n; cin >> n;

    for ( ull i = 0; i <= n; i++ )
        cout << "fib(" << i << ")=" << fib(i) << '\n';

}