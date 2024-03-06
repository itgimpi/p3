#include <bits/stdc++.h>
// moj prvi graf - retko se koristi, istorijski
using namespace std;
int main() {
    int n = 4;
    int e = 4;
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0; // nema veza na pocetku

    a[0][1] = 1; // usmeren graf
    /* za neusmeren
    a[0][1] = 1;
    a[1][0] = 1;
    */

    return 0; }
