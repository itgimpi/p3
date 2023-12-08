#include <bits/stdc++.h>
using namespace std; // Припадност тачке конвексном многоуглу
// https://petlja.org/biblioteka/r/Zbirka3/pripadnost_tacke_konveksnom_poligonu

typedef pair<int, int> tacka;
// tacka je par celih brojeva, prvi je x komp., drugi y

int ori(const tacka &a, const tacka &b, const tacka &c) {
    int xa = a.first, ya = a.second;
    int xb = b.first, yb = b.second;
    int xc = c.first, yc = c.second;
    // ako su koord. velike, koristi se long long
    // ll z = (ll)...
    int z = (xb - xa) * (yc-ya)-
            (xc - xa) * (yb-ya);
    if (z>0) return 1;
    if (z<0) return -1;
    return 0;
}

bool ista(const tacka &t1, const tacka &t2, const tacka &t3, const tacka &a) {
    int ori1 = ori(t1, t2, t3); // orijentacija t3 u odnosu na t1t2
    int ori2 = ori(t1, t2, a); // orijentacija a u odnosu na t1t2

    if ( ori1 == 0 || ori2 == 0 ) return true; // kolinearnost
    return ori1 == ori2; // sa iste strane
}

bool utrouglu( const tacka &t1, const tacka &t2, const tacka &t3, const tacka &a ) {
    // da li je ista orijentacija
    // za sve razlicite obilaske trougla...
    return  ista(t1, t2, t3, a) &&
            ista(t1, t3, t2, a) &&
            ista(t2, t3, t1, a);
}

bool pripada( const vector<tacka> &mnogo, const tacka &a ) {
    int n = mnogo.size();

    // fiksna tacka je 0, petlja ide po i od 1 do n-2
    //                                  i    i    i           i    
    for ( int i = 1; i < n-1; i++ ) // 012, 023, 034, ..., 0 n-2 n-1
        if ( utrouglu( mnogo[0], mnogo[i], mnogo[i+1], a ) )
            return true;
    // ako ne pripada nijednom trouglu, onda...
    return false;

}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n; // br. tacaka u mnogouglu
    //vector<pair<int, int>>mnogo(n);
    vector<tacka>mnogo(n);
    for (int i = 0; i < n; i++)
        cin >> mnogo[i].first >> mnogo[i].second;
        //       x komp.            y komp.

    int q; cin >> q; // broj upita, tacaka za ispitivanje
    while ( q-- ) {
        tacka a;
        cin >> a.first; // x komponenta
        cin >> a.second; // y komponenta
        if ( pripada( mnogo, a ) )
            cout << "da" << '\n';
        else 
            cout << "ne" << '\n';
    }

    return 0; }