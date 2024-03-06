#include <bits/stdc++.h>
using namespace std;
// Binary Tree, Unbalanced

struct cvor {
    int vrednost;
    cvor *levo, *desno; } ; 

cvor *napravi(int vredn) { // alokacija i inicijalizacija ( 0, vredn., 0)
    cvor *novi = new cvor;
    // proveri...
    novi->vrednost = vredn;
    novi->desno = novi->levo = nullptr; // novi trenutno nema potomke
    return novi; }

// ubacivanje se vrsi na poziciji list, ne valja
cvor *ubaci( cvor *stablo, int nova ){ // stablo, nova vred. za ubacivanje
    if ( stablo == nullptr ) // BC, prazno?
        return napravi(nova);
    if (nova < stablo->vrednost) // vredn. za ubacivanje je manja?
        stablo->levo = ubaci(stablo->levo, nova);
    else if (nova > stablo->vrednost)
        stablo->desno = ubaci(stablo->desno, nova);
    return stablo; }

void lekode(cvor *stablo) { // levo, koren, desno, sortiran niz
    if ( stablo != nullptr ) { // nije prazno?
        lekode(stablo->levo);
        cout << stablo->vrednost << ' ';
        lekode(stablo->desno); } }

void dekole(cvor *stablo) { // levo, koren, desno, sortiran niz
    if ( stablo != nullptr ) { // nije prazno?
        dekole(stablo->desno);
        cout << stablo->vrednost << ' ';
        dekole(stablo->levo); } }
        
int main() {
    cvor *stablo = nullptr; // prazno stablo :( 
    /* degenerisano stablo                  stablo
    stablo = ubaci(stablo, 50);             50
    stablo = ubaci(stablo, 100);           100
    stablo = ubaci(stablo, 200);*/         200
    stablo = ubaci(stablo, 100); //f-ja vraca adresu novog stabla
    stablo = ubaci(stablo, 200);
    stablo = ubaci(stablo, 50);

    stablo = ubaci(stablo, 50);stablo = ubaci(stablo, 100);stablo = ubaci(stablo, 200);

    lekode(stablo); cout << endl;
    dekole(stablo); cout << endl;




    
    return 0; }
