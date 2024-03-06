#include <bits/stdc++.h>
using namespace std;
// Binary Tree
struct cvor {
    int vrednost;
    cvor *levo, *desno; } ;

cvor *napravi(int vre) {
    cvor *novi = new cvor; // alokacija
    //provera...
    novi->vrednost = vre; // key, value
    novi->levo = novi->desno = nullptr; // trenutno nema potomaka
    return novi; }

cvor *ubaci(cvor *stablo, int nova) {
    if (stablo == nullptr) // BC, empty tree?
        return napravi(nova);
    // ako nije prazno...
    // ubacivanje neka ide u list, lako za kodiranje, ali ne omogucava balansiranost

    if ( nova < stablo->vrednost) // nova vrednost je manja?
        stablo->levo = ubaci(stablo->levo, nova); // idi levo...
    else if ( nova > stablo->vrednost ) // veca?
        stablo->desno = ubaci(stablo->desno, nova); // desno...
    // ovo je C++ struktura set, ne dozvoljava duplikate
    // ako se doda uslov da za jednakost novi cvor ide desno, onda je to multiset

    return stablo; }

// ispis stabla, L -> K -> D
void lekode(cvor *stablo) {
    if ( stablo != nullptr ) { // samo ako nije prazno...
        lekode(stablo->levo);
        cout << stablo->vrednost << ' ';
        lekode(stablo->desno);   } }

        
int main() {
    cvor *stablo = nullptr; // stablo je prazno
    stablo = ubaci(stablo, 200);
    stablo = ubaci(stablo, 100);
    stablo = ubaci(stablo, 50);

    lekode(stablo); // levo, koren, desno



    
    return 0; }
