#include <iostream>
using namespace std;
#define N 100
// Dobro resenje jer vodi racuna o ogranicenjima
int stek[N]; // Staticki niz sa 100 el, kapacitet steka
int sp; // pokazivac na mesto gde ide prvi sledeci el. inicijalno je 0

void dodaj(int element){ // Prekoracenje
    if ( sp == N )
        cout << "Stack is Full!" << endl;
    else 
        stek[sp++] = element; }

void oduzmi(){ // Potkoracenje
    if (sp>0)
        sp--; 
    else 
        cout << "Stack is Empty!" << endl;}

void vrh(){
    if (sp>0)
        cout << stek[sp-1] << endl;
    else
        cout << "Stack is Empty!" << endl; }

int vel() {
    return sp; }

bool prazan() {
    //return !sp;
    return sp == 0; }

int main() {
    
    dodaj(1); vrh();
    dodaj(2); vrh();
    dodaj(3); vrh();

    oduzmi(); vrh();
    oduzmi(); vrh();
    oduzmi(); vrh();

    for (int i = 0; i <= 110; i++) {
        dodaj(i+1); vrh(); }

    return 0; }
