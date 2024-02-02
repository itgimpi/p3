#include <bits/stdc++.h>
using namespace std;
/*Историја прегледача се понаша као стек 
јер се елементи само могу скидати и постављати на један крај историје 
(као последње посећени) и са тог краја се могу и скидати.*/ 
int main() { 
    stack<string> s;
    string adresa;
    while (getline(cin, adresa)) {
        if (adresa == "back") { // idi nazad...
            if (!s.empty()) // ako ima nešto na steku...
                s.pop(); // skloni sa vrha trenutnu poziciju
            if (!s.empty()) // ako i dalje ima...
                cout << s.top() << endl; // ispis adrese
            else
                cout << "-" << endl; } // nema prethodne
        else { // adresa
            cout << adresa << endl; // ispis...
            s.push(adresa); } } } // i postavljanje na stek
