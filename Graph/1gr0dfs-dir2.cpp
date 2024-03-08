#include <bits/stdc++.h> // DFS
using namespace std; // directed graph


void dodaj(int u, int v, vector<vector<int>>&veze){ // dodaj cvor od u do v
    veze[u].push_back(v); }

void dfs(int c, const vector<vector<int>>&veze, 
                vector<bool>&posecen) { // c je pocetni cvor
    if (!posecen[c]) { // ako nije do sada posecen...
        posecen[c] = true; // sada je posecen
        cout << c << ' ';
        for ( auto s : veze[c] ) // za sve susede od c
            dfs(s, veze, posecen); }
    return; }

int main() {
    int nc = 5; // br.cvorova, cin >>
    vector<vector<int>>veze(nc); 
    vector<bool>posecen(nc);

    posecen.resize(nc, false); // pre pocetka nema posecenih cvorova
    dodaj(0,1,veze); dodaj(0,2,veze); dodaj(1,3,veze); dodaj(3,2,veze); dodaj(3,4,veze);   

    dfs(0, veze, posecen); // DFS obilazak od 0

    return 0; }
