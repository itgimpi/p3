#include <bits/stdc++.h> // konveksni omotac, by Graham
using namespace std;
struct Tacka {
    int x, y;   };

int ori(const Tacka& t0, const Tacka& t1, const Tacka& t2) {
    long long d = (long long)(t1.x-t0.x)*(long long)(t2.y-t0.y) -
                  (long long)(t2.x-t0.x)*(long long)(t1.y-t0.y);
    if (d > 0)       return 1;
    else if (d < 0)      return -1;
    else      return 0; }

long long rast2(const Tacka& t1, const Tacka& t2) {
    int dx = t1.x - t2.x, dy = t1.y - t2.y;
    return dx*dx + dy*dy; }

void prostMnogougao(vector<Tacka>& tacke) {
// trazi desnu tacku sa maks. x koordinatom,
// ako ima vise tacaka sa maksimalnom x koordinatom bira donju, sa najmanjom y koordinatom
    auto max = max_element(begin(tacke), end(tacke), [](const Tacka& t1, const Tacka& t2) {
        return t1.x < t2.x || (t1.x == t2.x && t1.y > t2.y);    });
    swap(*begin(tacke), *max); // ide na početak niza - ona je centar kruga
    //const Tacka& t0 = tacke[0];
    const Tacka t0 = tacke[0];

// sort na osnovu ugla u odnosu vertikalnu polupravu koja polazi naviše iz centra kruga 
// a kolinearne na osnovu rastojanja od centra kruga
    sort(next(begin(tacke)), end(tacke),
        [t0](const Tacka& t1, const Tacka& t2) {
            int o = ori(t0, t1, t2);
            if (o == 0)
                return rast2(t0, t1) <= rast2(t0, t2);
            return o == 1;  });

    // obrce redosled tacaka na poslednjoj pravoj
    auto it = prev(end(tacke));
    while (ori(*prev(it), *it, t0) == 0)
        it = prev(it);
    reverse(it, end(tacke)); }

vector<Tacka> graham(vector<Tacka>& tacke) {
    vector<Tacka> omotac;
    prostMnogougao(tacke); // polazi od dole desno
    omotac.push_back(tacke[0]); // uzima prve dve tacke...
    omotac.push_back(tacke[1]);
    for (size_t i = 2; i < tacke.size(); i++) { // od trece tacke do zadnje
        // ako ima bar dve u omotacu... // i orijentacija nije dobra...
        while (omotac.size() >= 2 && ori(omotac[omotac.size()-2], omotac[omotac.size()-1], tacke[i]) != 1)
            omotac.pop_back(); //izbaci tacke iz omotaca
        omotac.push_back(tacke[i]);   } // ubaci prvu sledecu sa dobrom orijentacijom 
    return omotac; }


int main() {
    int n;   cin >> n;
    vector<Tacka> tacke(n);
    for (int i = 0; i < n; i++)
    	cin >> tacke[i].x >> tacke[i].y;
    vector<Tacka> omotac = graham(tacke);
    cout << omotac.size() << endl;
    for (const Tacka& t : omotac)
      cout << t.x << " " << t.y << endl;
    return 0;   }