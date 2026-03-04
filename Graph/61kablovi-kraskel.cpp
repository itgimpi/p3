#include <bits/stdc++.h>
using namespace std;
//typedef tuple<double, int, int> Grana;// duzina ide prva, zbog sortiranja
/* Краскелов алгоритам сортира све гране графа по дужини неопадајући 
и у сваком кораку у граф додаје најкраћу грану која не затвара циклус у односу на текући скуп грана. 
Гране не чине дрво, већ шуму. 
Свако дрво у тој шуми представља неку компоненту повезаности. 
Грана затвара циклус ако и само ако повезује два чвора који се налазе унутар исте компоненте повезаности. 
За ефикасно представљање компоненти повезаности тј. испитивање да ли су два чвора у истој компоненти, 
тј. ефикасно спајање две различите компоненте граном можемо користити структуру података за представљање дисјунктних подскупова 
(енгл. disjoint-set тј. union-find). */
int main() {
    ios_base::sync_with_stdio(false);
    int n, e; cin >> n >> e;
    vector<tuple<double, int, int>> grane(e);
    for (int i = 0; i < e; i++)  {
        int u, v; double d;
        cin >> u >> v >> d;
        grane[i] = make_tuple(d, u, v);  }

    sort(begin(grane), end(grane));  // sort po rastućem rastojanju
    
    vector<int> grupa(n);  // struktura za predstavljanje formiranih grupa
    //iota(begin(grupa), end(grupa), 0);  // za svaki element se pamti u kojoj je grupi, init 0, 1, 2, ... 
    for (int i = 0; i < n; i++) grupa[i] = i;

    double res = 0.0;  // ukupna duzina kablova
    int br = 0;  // broj grana u stablu (do n-1)
    for (int i = 0; i < e && br < n-1; i++) {
        int u = get<1>(grane[i]); // polazni čvor
        int v = get<2>(grane[i]); // dolazni čvor
        if (grupa[u] != grupa[v]) { // ako su u, v razlicite grupe, postavi ih u grupu gv
            int gu = grupa[u];  // gu je grupa polaznog čvora
            for (int j = 0; j < n; j++) // prođi kroz sve čvorove...
                if (grupa[j] == gu) // sve čvorove gu...
                    grupa[j] = grupa[v]; // prebaci u grupu sa čvorom v/
            double duzina = get<0>(grane[i]);
            res += duzina; // dodaj granu u stablo
            br++; } }
    cout << fixed << showpoint << setprecision(1) << res << endl;
    return 0; }