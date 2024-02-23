#include <iostream>
#include <set>
using namespace std;
//set - uvodni primer
int main() {
    //ios_base...
    set <unsigned>adrese;
    int n; cin >> n;
    while (n--) {
        unsigned adresa; cin >> adresa;
        adrese.insert(adresa); }

    cout << adrese.size();
    
    return 0; }
