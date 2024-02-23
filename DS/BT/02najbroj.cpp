#include <bits/stdc++.h>
using namespace std;
//map - uvodni primer
int main() {
    //ios_base...
    map <string, int>brpoj; // ime i br. poj.
    int n; cin >> n;
    while (n--) {
        string ime; cin >> ime;
        brpoj[ime]++; }

    //for ( auto b : brpoj )
        //cout << b.first << ' ' << b.second << endl;

    int res = 0;
    for ( auto b : brpoj )
        res = max(res, b.second);  

    cout << res;  
    
    return 0; }
