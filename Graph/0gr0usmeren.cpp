#include <bits/stdc++.h>
// moj prvi usmereni graf, matrice - retko se koristi, istorijski
// directed graph
using namespace std;
int main() {
    int n = 4; // num. of nodes
    int e = 4; // mumber of edges
    int veze[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            veze[i][j] = 0; // nema veza na pocetku

    veze[0][1] = 1; // usmeren graf, od 0 do 1
    veze[0][2] = 1; // grana 2, od 0 do 2
    veze[0][3] = 1; // grana 3, od 0 do 3
    veze[2][3] = 1; // grana 4, od 2 do 3

    for (int i = 0; i < n; i++) { // za sve redove...
        for (int j = 0; j < n; j++)
            cout << veze[i][j]; 
        cout << endl; }

    return 0; }
