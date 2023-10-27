#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int fib( int n ) {
    if ( n == 0 || n == 1 ) return 1; // Base Case
    return fib( n - 1 ) + fib( n - 2 ); } // Rec.

int main() {
    //int n; cin >> n;
    
    for ( int i = 0; i <= 50; i++ )
        cout << "fib(" << i << ")=" << fib( i ) << '\n';
}