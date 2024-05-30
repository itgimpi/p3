#include<bits/stdc++.h>
using namespace std; 

int main() {
    string plast, igla;
    cin >> plast >> igla;
    
    size_t poz = plast.find(igla);
    if ( poz != string::npos )
        cout << poz;
    else 
        cout << -1;  }