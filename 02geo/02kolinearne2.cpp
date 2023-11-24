#include <bits/stdc++.h>
using namespace std;
// https://petlja.org/biblioteka/r/Zbirka3/kolinearne_tacke

bool koltacke(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1) == 0; }

int main() {
    int x1, y1; cin >> x1 >> y1; // 2D, xy, z = 0
    int x2, y2; cin >> x2 >> y2;
    int res = 0;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x3, y3;
        cin >> x3 >> y3;
        if ( koltacke(x1, y1, x2, y2, x3, y3) ) res++;     }

    cout << res; 

    return 0; }