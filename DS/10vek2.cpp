#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<int> a; 
    string linija;
    while (cin >> linija)
        a.push_back(stoi(linija));
    int n = a.size();
    int zbir = 0;
    for (int i = 0; i < n; i++)
        zbir += a[i];
    double prosek = (double) zbir / (double) n; // prosek
     
    int imin = 0; // određuje se element koji najmanje odstupa od proseka
    for (int i = 1; i < n; i++)
        if (abs(a[i] - prosek) < abs(a[imin] - prosek))
            imin = i;
    cout << a[imin] << endl;
    return 0; }
