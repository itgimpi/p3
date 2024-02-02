#include <iostream>
#include <stack>
using namespace std;
//stek - uvodni primer
int main() { 
    stack<int> s; // napravi stek s, bez elemenata
    s.push(1);    // gurni na stek 1.                  s: 1
    s.push(2);    // gurni na stek 2.                  s: 1, 2
    s.push(3);    // gurni na stek 3.                  s: 1, 2, 3
    cout << s.top() << endl; // na vrhu je 3
    cout << s.size() << endl; // na steku je 3 el.
    s.pop(); // skloni sa vrha,                        s: 1, 2
    cout << s.top() << endl; // 2
    s.pop(); cout << s.top() << endl; //               s: 1
    s.pop(); cout << s.top() << endl; //               s: 

    s.push(1); s.push(2); s.push(3);//                 s: 1, 2, 3
    while (!s.empty()) {            // sve dok stek nije prazan...
        cout << s.top() << endl;    // ispis vrha
        s.pop(); } }                // skloni sa vrha
