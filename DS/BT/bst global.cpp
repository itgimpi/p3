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

cvor* stablo = nullptr;

cvor* napravi(int vre) {
    cvor* novi = new cvor(); // alociraj novi čvor...
    // provera da li je alokacija uspela...
    novi->vrednost = vre; // upiši vrednost
    novi->levo = novi->desno = nullptr; // trenutno nema potomke
    return novi; } // vrati adresu novog čvora

void ubaci(int nova) {
    if (stablo == nullptr) {// prazno stablo?
        stablo = napravi(nova); // ubaci novi u koren i vrati adresu
        return; }
    if (nova < stablo->vrednost) // nova vrednost je manja od korena?
        ubaci(stablo->levo, nova); // ubacije se u levo podstablo...
    else if (nova > stablo->vrednost) // veća? desno...
        ubaci(stablo->desno, nova);  } 


cvor* ubaci(cvor* stablo, int nova) {
    if (stablo == nullptr) // prazno stablo?
        return napravi(nova); // ubaci novi u koren i vrati adresu
    if (nova < stablo->vrednost) // nova vrednost je manja od korena?
        stablo->levo = ubaci(stablo->levo, nova); // ubacije se u levo podstablo...
    else if (nova > stablo->vrednost) // veća? desno...
        stablo->desno = ubaci(stablo->desno, nova);
    return stablo; } // vrati adresu korena

void ispis(cvor* stablo) {
    if (stablo != nullptr) {
        ispis(stablo->levo);
        ispis(stablo->desno);
        cout << stablo->vrednost << " "; } }

void ispis2(cvor* stablo) {
    if (stablo != nullptr) {
        cout << stablo->vrednost << " ";
        ispis2(stablo->levo);
        ispis2(stablo->desno); }    }

void ispis3(cvor* stablo) {
    if (stablo != nullptr) {
        ispis3(stablo->levo);
        cout << stablo->vrednost << " ";
        ispis3(stablo->desno); }    }

int najmanji(cvor* stablo) {
    while (stablo->levo != nullptr)
        stablo = stablo->levo;
    return stablo->vrednost; }

int najveci(cvor* stablo) {
    while (stablo->desno != nullptr)
        stablo = stablo->desno;
    return stablo->vrednost; }

// Iz stabla se uklanja čvor sa najmanjom vrednošću
void izbaciMin(cvor* stablo, int& x) {
    if (stablo == nullptr) return;  // iz praznog drveta nema šta da se briše
    if (stablo->levo == nullptr) {  // ako je levo podstablo prazno 
        cvor* desno = stablo->desno;  // brišemo stablo i vraćamo desno podstablo
        x = stablo->vrednost;
        delete stablo;
        stablo = desno;
        return; }        
    izbaciMin(stablo->levo, x);  // u suprotnom brišemo najmanji element levog poddrveta
    return; }

// Iz datog drveta uklanja dati čvor sa datom vrednošću
void izbaci(cvor* stablo, int x) {  // iz praznog stabla nema šta da se briše
    if (stablo == nullptr) return;
    if (x < stablo->vrednost)  // čvor se nalazi levo, pa se tamo i briše
        izbaci(stablo->levo, x);
    else if (x > stablo->vrednost)  // čvor se nalazi desno, pa se tamo i briše
        izbaci(stablo->desno, x);
    else {  // čvor se nalazi u korenu
        if (stablo->desno == nullptr) {
        // ako je desno podstablo prazno brišemo stablo i vraćamo levo podstablo
        cvor* levo = stablo->levo;
        delete stablo;
        stablo = levo; return;} 
        else {  // desno podstablo nije prazno, pa brišemo najmanji čvor iz njega i vrednost iz tog čvora upisujemo u stablo
            int min;
            izbaciMin(stablo->desno, min);
            stablo->vrednost = min; } }
    return ; // fizički čvor u kome je stablo se nije promenio
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

// brisanje celog stabla
void obrisi(cvor* stablo) {
    if (stablo != nullptr) {
        obrisi(stablo->levo);
        obrisi(stablo->desno);
        delete stablo; }    }

int main() {
    ubaci(10); // dodaje prvi el. i postavlja pokazivač na koren stabla
    ubaci(20); ubaci(30); ubaci(15); ubaci(5); ubaci(1);
    ispis(stablo); cout << endl;
    ispis2(stablo); cout << endl;
    ispis3(stablo); cout << endl;
    cout << najmanji(stablo) << '\n';
    cout << najveci(stablo) << '\n';
    cvor* s = sledbenik(stablo, 10);
    if (s != nullptr)
        cout << s->vrednost << '\n';
    izbaci(20);
    ispis(stablo);

    obrisi(stablo);



    return 0; }