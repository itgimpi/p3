#include <iostream>
#include <tuple>
using namespace std;
// torka - uvodni primer
int main() {
    tuple<int, int> a; // torka a je par, dvojka
    a = make_tuple(11, 12);
    cout << get<0>(a) << " " << get<1>(a) << endl;    

    tuple<int, int, int> b {21, 22, 23}; // torka b je trojka
    cout << get<0>(b) << " " << get<1>(b) << endl; 

    int p1, p2, p3;
    tie(p1, p2, p3) = b; // povezuje p1, p2 i p3 sa trojkom b

    cout << p1 << " " << p2 << " " << p3 << endl; 
    return 0; }
