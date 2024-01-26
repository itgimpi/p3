#include <iostream>
#include <vector>
using namespace std;
//Ako dimenzija nije unapred poznata, najbolje je da se koristi vektor vektora.
int main() {
    int n; cin >> n; // br. el. matrice
    vector<vector<int>> a(n); // alokacija prostora za n redova matrice
    for (int r = 0; r < n; r++) {
        a[r].resize(n); // u redu r se alocira prostor za n elemenata
        for (int k = 0; k < n; k++)
            cin >> a[r][k]; } // unos
    int trag = 0; // izracunava i ispisuje trag
    for (int i = 0; i < n; i++)
        trag += a[i][i];
    cout << trag << endl;
    return 0; }
