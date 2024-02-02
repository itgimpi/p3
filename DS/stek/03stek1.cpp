#include <iostream>
using namespace std;
int stek[1000]; // Stack Using Static Array
int sp; // Stack Pointer is Global Var.

void baci(int elem) {
    stek[sp] = elem;
    sp++; }

void izbaci() {
    sp--; }

void vrh() {
    cout << stek[sp-1] << endl; }

int main() {
    baci(1); vrh();
    baci(2); vrh();
    baci(3); vrh();
    izbaci(); vrh();
    izbaci(); vrh();
    izbaci(); vrh();
    return 0; }
