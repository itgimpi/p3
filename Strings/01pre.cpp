#include<bits/stdc++.h>
using namespace std; 

int main() {
    string oba;
    while ( getline( cin, oba ) ) { // omogucava bele znake
        int poz = oba.find(' ');            //PetarxPetrovic
        string ime = oba.substr(0, poz);    //012345
        string prezime = oba.substr(poz+1); // od poz+1 do kraja
        cout << prezime << ' ' << ime << '\n';
    }
}