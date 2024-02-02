#include <iostream>
using namespace std;
int stek[1000]; // Stack Using Static Array
int sp; // Stack Pointer is Global Var.

void baci(int elem) {
    if (sp < 1000)
        stek[sp++] = elem;
    else 
        cout << "Stack is full!" << endl; }

void izbaci() {
    if (sp>0)
        sp--;
    else 
        cout << "Stack is empty!" << endl;  }

void vrh() {
    if (sp>0)
        cout << stek[sp-1] << endl;
    else 
        cout << "Stack is empty!" << endl;
}

int main() {
    for (int i = 0; i < 1010; i++){
        baci(i); vrh();
    }
    return 0; }
