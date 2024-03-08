#include <bits/stdc++.h> // DFS
using namespace std; // directed graph

vector<vector<int>>veze; // veze su global, ne moraju da se prenose...
vector<bool>posecen;

void dodaj(int u, int v){ // dodaj cvor od u do v
    veze[u].push_back(v); }

void dfs(int c) { // c je pocetni cvor
    if (!posecen[c]) { // ako nije do sada posecen...
        posecen[c] = true; // sada je posecen
        cout << c << ' ';
        for ( auto s : veze[c] ) // za sve susede od c
            dfs(s); }
    return; }

int main() {
    int nc = 4; // br.cvorova, cin >>

    veze.resize(nc);
    posecen.resize(nc, false); // pre pocetka nema posecenih cvorova
    dodaj(0,1); dodaj(0,2); dodaj(1,3); dodaj(3,2); dodaj(3,4);   

    dfs(0); // DFS obilazak od 0

    return 0; }
