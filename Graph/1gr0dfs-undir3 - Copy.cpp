#include <bits/stdc++.h> // DFS using Stack
using namespace std; // directed graph
// sudedi se dodaju rucno, nije global

void dodaj(vector<vector<int>>&veze, int u, int v){ // dodaj cvor od u do v
    veze[u].push_back(v); 
    veze[v].push_back(u);  }
         // ne menjaju se                // menja se
void dfs(const vector<vector<int>>&veze, vector<bool>&posecen, int c) { // c je pocetni cvor
    // svi cvorovi koji treba se obidju idu prvo na stek
    stack<int>stek;
    stek.push(c); // pocetni ide na stek...
    posecen[c] = true; // prvi je kao posecen
    while ( !stek.empty() ) {  // sve dok na steku ima elemenata za obilazak...
        int cvor = stek.top(); // sl. el. za obradu se uzima sa steka...
        stek.pop();            // i sklanja se
        cout << cvor << ' ';          // obrada
        for ( auto s : veze[cvor] )
            if (!posecen[s]) { // za svakog komsiju cvora koji se obradjuje...
                posecen[s] = true;        // oznaci ga kao posecen...
                stek.push(s); } }         // ... i syavi na stek.

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
