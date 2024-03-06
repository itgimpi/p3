#include <bits/stdc++.h>
using namespace std;

void ispis(multiset<int>moci) {
    for ( auto m : moci)
        cout << m << ' ';
    cout << '\n';

}

int main() {
    //ios_base...
    multiset<int>moci;
    char c;
    while ( cin >> c ) {
        if ( c == 'i') {
            int moc; cin >> moc;
            moci.insert(moc); 
            //ispis(moci);
            }
        else if ( c == 'e' ) {
            int moc; cin >> moc;
            auto it = moci.find(moc);
            if ( it != moci.end()) // postoji moc?
                //moci.erase(moc);  // brise sve moci!!!
                moci.erase(it);
                //ispis(moci);
                }
        else if ( c == 'f' ) {
            int moc; cin >> moc;
            // auto it = moci.find(moc); NE VALJA!!!

            auto it = moci.lower_bound(moc);
            if ( it != moci.end() ) // postoji el. za ispis
                cout << *it;
            else // ne postoji
                cout << '-' << '\n'; 
            //ispis(moci);     }  
            }
  
    
    return 0; }
