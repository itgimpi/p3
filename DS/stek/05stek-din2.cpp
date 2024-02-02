#include <iostream>
using namespace std;
#define N 100
// stek pomocu din. mem.
struct cvor {          // 12B
    int pod;           // 4B
    cvor * link; }; // 8B

void dodaj( cvor **glava, int podatak) {
    cvor * novi = new cvor(); // alociraj (12B) za novi cvor
    // provera da li je alokacija uspela...
    novi->pod = podatak;
    novi->link = *glava;
    *glava = novi; } 

void vrh(cvor * glava) { // 
    if ( glava != nullptr ) // ako lista nije prazna...
        cout << glava->pod << endl; // ispis
    else  // inace
        cout << endl; } //novi red

void oduzmi( cvor **glava ) {
    if ( glava == nullptr ) // ako stek je prazan
        return; // ne radi nista
    cvor * tmp = * glava;
    *glava = tmp->link;
    delete tmp; }
// recimo sa stek vise ne treba...


int main() {
    cvor *top = nullptr; // inicijano ne pokazuje
    dodaj( &top, 1); // & je zbog promene vrednosti
    vrh(top); // ne menja se
    dodaj( &top, 2); // & je zbog promene vrednosti
    vrh(top); // ne menja se
    dodaj( &top, 3); //
    vrh(top); // ne menja se 
    dodaj( &top, 4); //
    vrh(top); // ne menja se 

    //brisisve( &top );



    return 0; }
