#include <iostream>
using namespace std;
/* Uređeno binarno stablo pretrage (nebalansirano).

Dodavanje je lako, uvek na mesto lista. 
Novi el. se poredi sa korenom, ako je manji ide levo, ako je veći desno. Ako su isti, ništa. To je set, sa razl. el..
Ako je multiset, nastavlja se levo.

Izbacivanje je malo teže. 
Ako se briše el. koji je manji od korena, on je u levom podstablu, ako je veći u desnom, ako su isti, briše se koren.
Ako je desno podstablo prazno, rešenje je levo. 
Ako nije, izbacuje se najmanji čvor iz desnog podstabla i ide u koren. Ili najveći el. levog podstabla.

Najmanji je krajnji levi potomak korena. 
Sledbenik nekog broja? Za prazno stablo ne postoji. 
Ako je koren manji ili jednak od broja, sledbenik je u desnom podstablu, jer mora da bude veći. Ako nema desnog, ništa.
Inače, sledbenik je u levom podstablu. Ako postoji, nastavi, inače je koren sledbenik.
Ову функцију је могуће имплементирати и нерекурзивно.*/

struct cvor {
    int vrednost;
    cvor *levo, *desno; };

cvor* napravi(int vre) {
    cvor* novi = new cvor(); // alociraj novi čvor...
    // provera da li je alokacija uspela...
    novi->vrednost = vre; // upiši vrednost
    novi->levo = novi->desno = nullptr; // trenutno nema potomke
    return novi; } // vrati adresu novog čvora

cvor* ubaci(cvor* stablo, int nova) {
    if (stablo == nullptr) // prazno stablo?
        return napravi(nova); // ubaci novi u koren i vrati adresu
    if (nova < stablo->vrednost) // nova vrednost je manja od korena?
        stablo->levo = ubaci(stablo->levo, nova); // ubacije se u levo podstablo...
    else if (nova > stablo->vrednost) // veća? desno...
        stablo->desno = ubaci(stablo->desno, nova);
    return stablo; } // vrati adresu korena

void ledeko(cvor* stablo) {
    if (stablo != nullptr) {
        ledeko(stablo->levo);
        ledeko(stablo->desno);
        cout << stablo->vrednost << " "; } }

void kolede(cvor* stablo) {
    if (stablo != nullptr) {
        cout << stablo->vrednost << " ";
        kolede(stablo->levo);
        kolede(stablo->desno); }    }

void lekode(cvor* stablo) {
    if (stablo != nullptr) {
        lekode(stablo->levo);
        cout << stablo->vrednost << " ";
        lekode(stablo->desno); }    }

void dekole(cvor* stablo) {
    if (stablo != nullptr) {
        dekole(stablo->desno);
        cout << stablo->vrednost << " ";
        dekole(stablo->levo); }    } 

int najmanji(cvor* stablo) {
    while (stablo->levo != nullptr)
        stablo = stablo->levo;
    return stablo->vrednost; }

int najveci(cvor* stablo) {
    while (stablo->desno != nullptr)
        stablo = stablo->desno;
    return stablo->vrednost; }

// Iz stabla se uklanja čvor sa najmanjom vrednošću
cvor* izbaciMin(cvor* stablo, int& x) { // 
    if (stablo == nullptr) return nullptr;  // iz praznog drveta nema šta da se briše
    if (stablo->levo == nullptr) {  // ako je levo podstablo prazno 
        cvor* desno = stablo->desno;  // briše se koren i vraća desno podstablo
        x = stablo->vrednost;
        delete stablo;
        return desno; }        
    stablo->levo = izbaciMin(stablo->levo, x);  // ako levo nije prazno, briše se najmanji element levog podstabla
    return stablo; }

cvor* izbaci(cvor* stablo, int x) { // Iz stabla se izbacuje čvor sa datom vrednošću 
    if (stablo == nullptr) return nullptr;  // iz praznog stabla nema šta da se briše
    if (x < stablo->vrednost)  // čvor je levo, ...
        stablo->levo = izbaci(stablo->levo, x);
    else if (x > stablo->vrednost)  // čvor je desno, ...
        stablo->desno = izbaci(stablo->desno, x);
    else {  // čvor je u korenu...
        if (stablo->desno == nullptr) { //ako je desno podstablo prazno briše se stablo i vraća levo podstablo
            cvor* levo = stablo->levo;
            delete stablo;
            return levo; } 
        else {  //desno podstablo nije prazno, briše se najmanji čvor iz njega, vrednost upisuje u koren
            int min;
            stablo->desno = izbaciMin(stablo->desno, min);
            stablo->vrednost = min; } }
    return stablo; // koren se nije promenio
    }

cvor* sledbenik(cvor* stablo, int x) {
    if (stablo == nullptr) return nullptr;
    if (stablo->vrednost <= x)
        return sledbenik(stablo->desno, x);
    else {
        cvor* sl = sledbenik(stablo->levo, x);
        if (sl != nullptr)
            return sl;
        return stablo;  }  }

void obrisi(cvor* stablo) { // brisanje celog stabla
    if (stablo != nullptr) {
        obrisi(stablo->levo);
        obrisi(stablo->desno);
        delete stablo; }    }

int main() {
    cvor* stablo = nullptr;
    stablo = ubaci(stablo, 200); // dodaje prvi el. i postavlja pokazivač na koren stabla
    stablo = ubaci(stablo, 100); stablo = ubaci(stablo, 300); //stablo = ubaci(stablo, 15); stablo = ubaci(stablo, 5); stablo = ubaci(stablo, 1);
    stablo = ubaci(stablo, 50); stablo = ubaci(stablo, 150);
    ledeko(stablo); cout << endl; // 100, 300, 200
    kolede(stablo); cout << endl; // 200, 100, 300
    lekode(stablo); cout << endl; // 100, 200, 300
    dekole(stablo); cout << endl; // 100, 200, 300
    cout << najmanji(stablo) << '\n';
    cout << najveci(stablo) << '\n';
    cvor* s = sledbenik(stablo, 10);
    if (s != nullptr)
        cout << s->vrednost << '\n';
    stablo = izbaci(stablo, 20);
    //ispis(stablo);

    obrisi(stablo);



    return 0; }