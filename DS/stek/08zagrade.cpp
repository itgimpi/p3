#include <iostream>
#include <stack>
using namespace std;

bool uparena(char oz, char zz) { // provera da li su dve zadrade uparene
    return (oz == '(' && zz == ')') || (oz == '[' && zz == ']') || (oz == '{' && zz == '}'); }

bool otvorena(char c) { // da li je zagrada otvorena?
    return c == '(' || c == '[' || c == '{'; }

bool zatvorena(char c) { // da li je zagrada zatvorena?
    return c == ')' || c == ']' || c == '}'; }

int main() {
    string izraz; cin >> izraz;
    stack<char> zagrade; // stek za zagrade
    bool OK = true; // za sada je sve kako treba...

    for (char c : izraz) { // obrada izraza
        if (otvorena(c)) // ako je otvorena - na stek
            zagrade.push(c);
        else if (zatvorena(c)) { // zatvorena?
            if (zagrade.empty() || !uparena(zagrade.top(), c)) {
                OK = false;         // ako je stek prazan ili nije uparena sa vrhom steka...
                break; }            // ...nisu uparene
            zagrade.pop(); } }      // poklapaju se, skini otvorenu sa vrha
    
    if (!zagrade.empty()) // stek mora da bude prazan!
        OK = false;
        
    cout << (OK ? "tacno" : "netacno") << endl;
    // if ( OK ) cout << "tacno" else cout << "ne";
    return 0; }
