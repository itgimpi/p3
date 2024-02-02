#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

bool jeoperator(char c) { // da li je je operator?
    return c == '+' || c == '*'; }

int primeni(char op, int op1, int op2) { // ...operator
    int v;
    switch(op) { // zavisno od operatora...
        case '+': v = op1 + op2; break;
        case '*': v = op1 * op2; break; } 
    return v; } // ...vrati vrednost

int main() {
    string izraz; cin >> izraz; //ulaz
    stack<int> s;
    for (char c : izraz) { // obrada izraza
        if (isdigit(c)) // cifre idu na...
            s.push(c - '0'); // stek, 48->0, 49->1, ...
        else if (jeoperator(c)) { // ako je operator...
            int op2 = s.top(); s.pop(); //operandi su... 
            int op1 = s.top(); s.pop(); //na vrhu steka
            s.push(primeni(c, op1, op2)); } } //primena
            
    cout << s.top() << endl; // vrednost je na vrhu steka
    return 0; }
