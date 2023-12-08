#include <bits/stdc++.h>
using namespace std; // Припадност тачке конвексном многоуглу
// https://petlja.org/biblioteka/r/Zbirka3/pripadnost_tacke_konveksnom_poligonu

typedef pair<int, int> tacka;            // ДЦ O(q log n)

int ori( const tacka &a, const tacka &b, const tacka &c ) {
    int xa = a.first, ya = a.second;
    int xb = b.first, yb = b.second;
    int xc = c.first, yc = c.second;

    int z =     ( xb - xa ) * ( yc - ya ) 
              - ( xc - xa ) * ( yb - ya );
    if (z>0) return 1;
    if (z<0) return -1;
    return 0;
}

bool ista( const tacka &t1, const tacka &t2, const tacka &t3, const tacka &a ) {
    int ori1 = ori( t1, t2, t3 );
    int ori2 = ori( t1, t2, a );

    if ( ori1 == 0 || ori2 == 0 ) return true;
    return ori1 == ori2; }

bool utrouglu( const tacka &t1, const tacka &t2, const tacka &t3, const tacka &a ) {
    return  ista( t1, t2, t3, a ) &&
            ista( t1, t3, t2, a ) &&
            ista( t2, t3, t1, a ); 
}

//bool pripada( const vector<pair<int, int>> &mnogo, pair<int, int> a ) {
bool pripada( const vector<tacka> &mnogo, const tacka &a, int dg, int gg ) {
    // BC, kad deljenjem ostane 1 trougao
    if ( dg + 1 == gg ) // samo 3 tacke
        return utrouglu(mnogo[0], mnogo[dg], mnogo[gg], a) ;
    
    //int s = (dg + gg) / 2;
    int s = dg + (gg - dg) / 2;
    // ako je mnogougao dat u CCW ( kontra od skazaljke )
    if ( ori( mnogo[0], mnogo[s], a ) == 1 )
        return pripada(mnogo, a, s, gg);
    else
        return pripada(mnogo, a, dg, s);




 }

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n; // br. tacaka u mnogouglu
    vector<tacka>mnogo(n);
    for (int i = 0; i < n; i++)
        cin >> mnogo[i].first >> mnogo[i].second;

    int q; cin >> q; // broj upita, tacaka za ispitivanje
    for (int i =0; i < q; i++) {
        tacka a;
        cin >> a.first; // x komponenta
        cin >> a.second; // y komponenta
        //                      dg  gg
        if ( pripada( mnogo, a, 1, n-1 ) ) // fiksirana 0
            cout << "da" << '\n';
        else 
            cout << "ne" << '\n';
    }

    return 0; }