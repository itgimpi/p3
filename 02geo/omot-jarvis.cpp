#include <bits/stdc++.h> // konveksni omotac, by Jarvis
using namespace std;
struct Tacka { int x, y; };

int ori(const Tacka& t0, const Tacka& t1, const Tacka& t2) {
    long long z = (long long)(t1.x-t0.x)*(long long)(t2.y-t0.y) -
                  (long long)(t2.x-t0.x)*(long long)(t1.y-t0.y);
    if (z > 0) return 1;
    else if (z < 0) return -1;
    else return 0; }

bool izmedju(const Tacka& t1, const Tacka& t2, const Tacka& t3) { // ako su kolinearne...
    return (t1.x < t2.x && t2.x < t3.x) || // t2 izmedju t1 i t3?
           (t1.x > t2.x && t2.x > t3.x) ||
           (t1.x == t2.x && t2.x == t3.x && t1.y < t2.y && t2.y < t3.y) ||
           (t1.x == t2.x && t2.x == t3.x && t1.y > t2.y && t2.y > t3.y); }

vector<Tacka> jarvis(vector<Tacka>& tacke) {
    vector<Tacka> omotac;
    int prva = distance(begin(tacke), min_element(begin(tacke), end(tacke), 
        [] (const Tacka& t1, const Tacka& t2) { // levo dole  tacka - indeks
        return t1.x < t2.x || (t1.x == t2.x && t1.y < t2.y); }));
    int trenutna = prva; // polazi se od levo dole 
    do {
        omotac.push_back(tacke[trenutna]);
        int sl = 0; // sledeca tacka je inicijalno prva u nizu tacaka
        for (size_t i = 1; i < tacke.size(); i++) { // sve ostale...
            int o = ori(tacke[trenutna], tacke[sl], tacke[i]); // ori=1, veci ugao
            if (sl == trenutna || o == 1 || (o == 0 && izmedju(tacke[trenutna], tacke[sl], tacke[i])))
                sl = i; }
        trenutna = sl;
    } while (trenutna != prva);
    return omotac; }


int main() {
    int n; cin >> n;
    vector<Tacka> tacke(n);
    for (int i = 0; i < n; i++)
        cin >> tacke[i].x >> tacke[i].y;
    vector<Tacka> omotac = jarvis(tacke);
    cout << omotac.size() << endl;
    for (const Tacka& t : omotac)
        cout << t.x << " " << t.y << endl;
    return 0; }