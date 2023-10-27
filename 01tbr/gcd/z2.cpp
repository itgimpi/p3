#include <bits/stdc++.h>
using namespace std;
int nzs(int a, int b){
    return a*b / __gcd(a,b); 
}
int main() {
    int i, j , k; cin >> i,j,k;
    int p1 = nzs(i,j);
    int p2 = nzs(p1,k);
    cout << p2/i * 200 + p2/j * 500 + p2/k * 1000;
    return 0;
}