#include <iostream>
#include <cmath>
using namespace std;
/* Učitava se najviše 100 brojeva. Odredi element koji najmanje odstupa od proseka.*/
int main() {
    int a[100];
    int n; cin >> n; // Broj elemenata
    for (int i = 0; i < n; i++) // Unos
        cin >> a[i];
    int zbir = 0; // 
    for (int i = 0; i < n; i++)
        zbir += a[i]; // zbir
    double prosek = (double) zbir / (double) n; // prosek
    // odredi i ispiši element koji najmanje odstupa pod proseka
    int inaj = 0;
    for (int i = 1; i < n; i++)
        if (abs(a[i] - prosek) < abs(a[inaj] - prosek))
            inaj = i;
    cout << a[inaj] << endl;
    return 0; }
