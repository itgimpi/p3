#include <bits/stdc++.h>
using namespace std;

int lcm (int a, int b){
    return a/__gcd(a, b)*b;
}

int main() {

    int a, b, c; cin >> a >> b >> c;

    int res = lcm( a, b );
    res = lcm( res, c );
    cout << res/a*200+res/b*500+res/c*1000;


    return 0; }