#include <iostream>
#include <tuple>
using namespace std;
//par - uvodni primer
int main() {
    pair<int, int> a, b; // a i b su parovi
    // prvi je int i drugi
    a.first = 11; a.second = 12; // dodele vrednosti
    b.first = 21; b.second = 22;
    // drugi nacin deklarise c kao par i dodele vrednosti...
    pair<int, int> c = make_pair(31, 32);
    // treci nacin, noviji
    pair <int, int> d {41, 42};
    // ispis
    cout << a.first << " " << a.second << endl;
    cout << c.first << " " << c.second << endl;
    cout << d.first << " " << d.second << endl;
    int v1, v2; // v1 i v2 su prom. nisu parovi 
    tie(v1, v2) = b; // iz para b upisi vred. u prom. v1, v2
    cout << v1 << " " << v2 << endl; 
    return 0; }
