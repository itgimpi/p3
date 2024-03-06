#include <bits/stdc++.h>
using namespace std;
//magija
int main() {
    //ios_base...
    multiset<int>madzije;
    char c;
    while ( cin >> c ) {
        if ( c == 'i' ) {
            int madzija; cin >> madzija;
            madzije.insert(madzija); }
        else if ( c == 'e' ) {
            int madzija; cin >> madzija;
            auto it = madzije.find(madzija);
            if ( it != madzije.end() )
                //madzije.erase(madzija); } <-izbaci sva pojavljivanja
                madzije.erase(it); }
        else if ( c == 'f' ) {
            int madzija; cin >> madzija;
            //auto it = madzije.find(madzija); // ne valja, treba prva vr. koja je >=
            auto it = madzije.lower_bound(madzija);
            if (it != madzije.end())
                cout << *it << '\n';
            else 
                cout << '-' << '\n'; } }


    
    return 0; }
