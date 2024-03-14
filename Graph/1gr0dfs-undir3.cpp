#include <bits/stdc++.h> // DFS
using namespace std; // directed graph
// sudedi se dodaju rucno, nije global

void dodaj(vector<vector<int>>&veze, int u, int v){ // dodaj cvor od u do v
    veze[u].push_back(v); 
    veze[v].push_back(u);  }

void dfs(const vector<vector<int>>&veze, vector<bool>&posecen, int c) { // c je pocetni cvor
    if (!posecen[c]) { // ako nije do sada posecen...
        posecen[c] = true; // sada je posecen

        cout << c << ' ';
        for ( auto s : veze[c] ) // za sve susede od c
            dfs(veze, posecen, s); }
    return; }

int main() {
    int nc = 9; // br.cvorova, cin >>
    int nv = 12;
    
    vector<vector<int>>veze(nc); // veze nisu global, moraju da se prenose...
    vector<bool>posecen(nc, false);  // pre pocetka nema posecenih cvorova

    dodaj(veze,0,1); dodaj(veze,0,3); 
    dodaj(veze,1,2); dodaj(veze,1,4); 
    dodaj(veze,2,5);  
    dodaj(veze,3,4); dodaj(veze,3,6); 
    dodaj(veze,4,5); dodaj(veze,4,7); 
    dodaj(veze,5,8);  
    dodaj(veze,6,7); 
    dodaj(veze,7,8);  


    dfs(veze, posecen, 0); // DFS obilazak od 0

    return 0; }
