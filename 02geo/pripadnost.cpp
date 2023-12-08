#include <bits/stdc++.h>
using namespace std; // Припадност тачке конвексном многоуглу
// https://petlja.org/biblioteka/r/Zbirka3/pripadnost_tacke_konveksnom_poligonu

typedef pair<int, int> tacka; // O(q n)

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
bool pripada( const vector<tacka> &mnogo, const tacka &a ) {
    int n = mnogo.size();
    // triangilacija 012, 023, 034, ... 0 n-2 n-1
    for ( int i = 1; i < n-1; i++ ) // za svaki trougao
        // ako pripada nekom trouglu...
        if ( utrouglu( mnogo[0], mnogo[i], mnogo[i+1], a ) )
            return true;
    // ne pripada nijednom trouglu...
    return false; }

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
        if ( pripada( mnogo, a ) )
            cout << "da" << '\n';
        else 
            cout << "ne" << '\n';
    }

    return 0; }