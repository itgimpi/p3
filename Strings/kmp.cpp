#include<bits/stdc++.h>
using namespace std; 
// Pretraga igle u plastu, koristeci KMP

void nps( const string &igla, vector<int>&kmp ) { // najveci prefix sufix
    int duz = 0; // duzina naj. p. s.
    kmp[0] = 0; // samo prvo slovo u igli
    int i = 1; // ostala slova
    while( i < igla.length() ) {
        if ( igla[i] == igla[duz] ) { // poklapanje?
            duz++; // azurira se dnps
            kmp[i] = duz; // zapamti se 
            i++;  } // predji na sl. kmp
        else { // nepoklapanje
            if ( duz != 0 )
                duz = kmp[duz-1];
            else { // duz == 0
                kmp[i] = 0;
                i++;
            }

        }
    }


}

void nadji(const string &igla, const string &plast) {
    vector<int>kmp(igla.length());
    nps(igla, kmp); // odredi kmp za iglu

    int i = 0, p = 0;
    while ( p < plast.length() ) { // sve dok...
        if ( igla[i] == plast[p] ) { // poklapanje
            i++;
            p++;
        }
        if ( i == igla.length() ) {
            cout << p - i << ' ';
            i = kmp[i-1]; 
        }

        else if ( p < plast.length() && igla[i] != plast[p] ) {
            if ( i != 0 )
                i = kmp[i-1];
            else // i == 0
                p++;
        }

    }

}

int main() {
    string tekst = "AAAAAAABBAAAAAA"; // plast
    string uzorak = "AAAA"; // igla

    nadji(uzorak, tekst);
     
    
   

  }