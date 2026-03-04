#include <bits/stdc++.h>
using namespace std;
/* Kraskel sortira sve grane grafa rastuce - neopadajuce po duzini, 
 u svakom koraku se dodaje najkraca grana koja ne zatvara ciklus. Grane nisu stablo, nego suma.
Svako stablo u šumi je komponenta povezanosti
Свако дрво у тој шуми представља неку компоненту повезаности и грана затвара циклус 
ако и само ако повезује два чвора који се налазе унутар исте компоненте повезаности. 
За ефикасно представљање компоненти повезаности тј. испитивање да ли су два чвора у истој компоненти, 
тј. ефикасно спајање две различите компоненте граном можемо користити структуру података 
за представљање дисјунктних подскупова (енгл. disjoint-set тј. union-find). */

struct cvor { // struktura podataka za predstavljanje disjunktnih podskupova (union-find)
    int roditelj;
    int rang; }; // bila bi visina, da se ne vrsi dodatno kompresija staze

void napravi(vector<cvor>& skup) { // inicijalizacija - svaki cvor je u posebnoj komponenti
    for (size_t i = 0; i < skup.size(); i++) {
        skup[i].roditelj = i;
        skup[i].rang = 0;   } }

int nadji(vector<cvor>& skup, int i) { // pronalazenje predstavnika cvora i 
    while (skup[i].roditelj != i) {
        // kompresija staze - svaki drugi cvor ukazuje na svog dedu
        skup[i].roditelj = skup[skup[i].roditelj].roditelj;
        i = skup[i].roditelj;   }
    return i; }

bool spoji(vector<cvor>& skup, int v1, int v2) { // unija dve komponente
    int koren1 = nadji(skup, v1);
    int koren2 = nadji(skup, v2);
    if (koren1 == koren2)     // cvorovi v1 i v2 su u istoj komponentni
        return false;
   
    if (skup[koren1].rang < skup[v2].rang)  // granu vucemo od grupe sa manjim rangom ka grupi sa vecim
        skup[koren1].roditelj = koren2;   
    else if (skup[koren1].rang > skup[koren2].rang) 
        skup[koren2].roditelj = koren1;     
    else {                                  // rangovi su isti, pa se rang (visina) novog drveta povecava
        skup[koren2].roditelj = koren1;
        skup[koren1].rang++;     }
    return true; }

// tip grane grafa - duzina ide prva, zbog sortiranja
//typedef int Cvor;
//typedef double Duzina;
//typedef tuple<double, int, int> Grana;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n; int e; cin >> e;
    vector< tuple<double, int, int> > grane(e);
    for (int i = 0; i < e; i++)  {
        int u, v; double d;
        cin >> u >> v >> d;
        grane[i] = make_tuple(d, u, v); }
    sort(begin(grane), end(grane));     // sortirane grane u neopadajucem redosledu duzina
    vector<cvor> skup(n);     // struktura podataka za predstavljanje formiranih grupa
    napravi(skup);
    double res = 0.0;     // ukupna duzina kablova
    int br = 0;     // broj trenutno dodatih grana
    for (int i = 0; i < e && br < n-1; i++)
        // ako grana spaja cvorove u dve razlicite komponente, onda se komponente spajaju
        if (spoji(skup, get<1>(grane[i]), get<2>(grane[i]))) {
            res += get<0>(grane[i]); // dodaje granu u stablo
            br++; }    
    cout << fixed << showpoint << setprecision(1) << res << endl;
    return 0; }