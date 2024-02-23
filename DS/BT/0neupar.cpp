#include <iostream>
#include <set>
using namespace std;
//set - uvodni primer
int main() {
    //ios_base...
    set <int> s;
    int n; cin >> n;
    while (n--) {
        int broj; cin >> broj;
        auto it = s.find(broj);
        if(it != s.end()){
            s.erase(it);
        }
        else{
            s.insert(broj);
        }

        cout<< *s.begin();
        }

    
    
    return 0; }
