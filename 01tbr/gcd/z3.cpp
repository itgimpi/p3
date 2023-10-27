#include <bits/stdc++.h>
using namespace std;
int nzs(int a, int b){
    return a*b / __gcd(a,b); 
}
int main() {
    int n; cin >> n;
    int res = 1;
    for(int i = 2; i<=n;i++){
        res = nzs(res, i);
    }
    cout << res;
    return 0;
}