#include <bits/stdc++.h>
using namespace std;
// https://petlja.org/biblioteka/r/Zbirka3/sa_iste_strane

int orijentacija(int x1, int y1, int x2, int y2) {
    int z = x1 * y2 - x2 * y1; // vek.pr. za 2 vektora, koji su u xy ravni
    if ( z > 0 ) return 1; // ako je vektor +, prema meni, 1
    if ( z < 0 ) return -1; // -, od mene, -1
    return 0; } // kolinearnost

bool ista(int xb, int yb, int xt, int yt, int x, int y) { // vek 0B, vek 0T i vek 0i
    return orijentacija(xb, yb, xt, yt) == orijentacija(xb, yb, x, y); }
    // ako je orijent. prava i tacka T
    // ista sa orijent. prava i tacka koja se ispituje, sa iste strane su!

int main() {
    // prvo se unose poc. i kraj vektora, koji odredjuju pravu
    int xa, ya; cin >> xa >> ya; // 2D, xy, z = 0
    int xb, yb; cin >> xb >> yb;

    xb-=xa; yb-=ya; // translacija vektora, tako da mu pocetak bude (0,0)

    int xt, yt; cin >> xt >> yt; // tacka T, odredjuje 1/2 ravan koja se broji
    xt-=xa; yt -= ya; // trans. T

    int res = 0;
    int n; cin >> n;  // n tacaka se proverava

    for (int i = 0; i < n; i++) { // za svaku...
        int x, y; cin >> x >> y; // koordinate i-te tacke
        x-=xa; y-=ya; // translacija...
        if ( ista(xb, yb, xt, yt, x, y) ) res++; } // provera sa koje strane je (x, y)

    cout << res; 

    return 0; }