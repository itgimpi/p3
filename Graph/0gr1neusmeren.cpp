#include <bits/stdc++.h>
// moj prvi neusmereni graf, matrice - retko se koristi, istorijski
// undirected graph
using namespace std;
int main() {
    int n = 4;
    int e = 4;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0; // nema veza na pocetku

    a[0][1] = 1; // veza od 0 do 1
    a[1][0] = 1; // postoji i veza od 1 do 0

    a[0][2] = 1; // grana od 0 do 2
    a[2][0] = 1; // grana od 2 do 0

    a[0][3] = 1; // 
    a[3][0] = 1; // 
    
    a[2][3] = 1; // 
    a[3][2] = 1; // 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j]; 
        cout << endl; }

    return 0; }