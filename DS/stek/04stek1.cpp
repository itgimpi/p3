#include <iostream>
using namespace std;
// Nije dobro resenje jer ne vodi racuna o ogranicenjima
int stek[100]; // Staticki niz sa 100 el, kapacitet steka
int sp; // pokazivac na mesto gde ide prvi sledeci el. inicijalno je 0

void dodaj(int element){
    stek[sp] = element;
    sp++; }

void oduzmi(){
    sp--; }

void vrh(){
    cout << stek[sp-1] << endl;
}

int main() {
    dodaj(1); vrh();
    dodaj(2); vrh();
    dodaj(3); vrh();
    oduzmi(); vrh();
    oduzmi(); vrh();
    oduzmi(); vrh();
    for (int i = 0; i <= 110; i++) {
        dodaj(i); vrh();
    }

    return 0; }
