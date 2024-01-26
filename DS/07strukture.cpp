#include <bits/stdc++.h>
using namespace std;
struct razlomak {
    int broj, ime; };

void skrati(razlomak& r) {
    int nzd = __gcd(r.broj, r.ime);
    r.broj /= nzd;
    r.ime /= nzd; }

razlomak saberi(const razlomak& r1, const razlomak& r2) {
    razlomak zbir;
    zbir.broj = r1.broj * r2.ime + r2.broj * r1.ime;
    zbir.ime = r1.ime * r2.ime;
    skrati(zbir);
    return zbir; }

int main() { // struct razlomak r1; r1.broj = 3; r1.ime = 5;
    razlomak r1{3, 5}, r2{2, 3};
    razlomak zbir = saberi(r1, r2);
    cout << zbir.broj << "/" << zbir.ime << endl;
    return 0; }