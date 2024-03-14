#include <bits/stdc++.h> // DFS
using namespace std; // directed graph
// sudedi se dodaju rucno, primer sa 9 cvorova
vector<vector<int>>veze; // veze su global, ne moraju da se prenose...
vector<bool>posecen;

void dodaj(int u, int v){ // dodaj cvor od u do v
    veze[u].push_back(v); 
    veze[v].push_back(u);  }

void dfs(int c) { // c je pocetni cvor
    stack<int>stek;
    stek.push(c);
    posecen[c] = true;
    while ( !stek.empty() ) { // dfs se vrsi sve dok ima cvorova na steku
        int cvor = stek.top(); stek.pop();
        cout << cvor << ' ';
        for ( auto s : veze[cvor] ) // za sve susede cvora...
            if ( !posecen[s] ) {
                posecen[s] = true;
                stek.push(s); }  }

    return; }

int main() {
    int nc = 9; // br.cvorova, cin >>
    int nv = 12;

    veze.resize(nc);
    posecen.resize(nc, false); // pre pocetka nema posecenih cvorova
    dodaj(0,1); dodaj(0,3); 
    dodaj(1,2); dodaj(1,4); 
    dodaj(2,5);  
    dodaj(3,4); dodaj(3,6); 
    dodaj(4,5); dodaj(4,7); 
    dodaj(5,8);  
    dodaj(6,7); 
    dodaj(7,8);  


    dfs(0); // DFS obilazak od 0

    return 0; }
