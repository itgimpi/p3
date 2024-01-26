#include <bits/stdc++.h>
using namespace std;
/*Sa ulaza se učitava n datuma. Serbian. Odredi najkasniji od njih.*/
tuple<int,int,int> unos() {
    int d, m, g; cin >> d >> m >> g; // unosi se srpski
    // glavni deo, napravi se trojka godina, mesec i dan
    return make_tuple(g, m, d); } // i vrati se main-u

void ispis(const tuple<int, int, int>& datum) { // serbian
    cout << get<2>(datum) << '.' << get<1>(datum) << '.' << get<0>(datum) << '.' << endl; }

void ispis2(const tuple<int, int, int>& datum) { // us
    cout << get<1>(datum) << '/' << get<2>(datum) << '/' << get<0>(datum) << endl; }

int main() {
    int n; cin >> n; // broj datuma
    tuple<int, int, int> max_datum = unos(); // trojka za prvi datum
    for (int i = 1; i < n; i++) { // jos n-1 datuma
        tuple<int, int, int> datum = unos();
        // max_datum = max(datum, max_datum);
        if (datum > max_datum) // poređenje je po g, m, d
            max_datum = datum; }

    ispis(max_datum);
    ispis2(max_datum); // US

    return 0; }
