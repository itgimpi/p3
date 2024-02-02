#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    stack<string> s; // s je stek
    string red;   // za unos

    while (cin >> red) // sve dok ima nesto na ulazu...
        s.push(red);   // svaki red ide na stek

    while (!s.empty()) {  // sve dok ima nesto na steku...
        cout << s.top() << endl; // sta je na vrhu?
        s.pop(); }        // izbaci sa steka
    return 0; }
