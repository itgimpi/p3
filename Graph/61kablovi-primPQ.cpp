#include <bits/stdc++.h>
using namespace std;
const double INF = numeric_limits<double>::infinity();
/* 

У једном рачунарском кабинету потребно је поставити мрежу тако да су сви рачунари међусобно повезани, али тако да се употреби што мање кабла. 
Ако је познато који се рачунари могу повезати кабловима и које је растојање између њих, 
напиши програм који одређује најмању укупну дужину каблова.

Улаз
Са стандардног улаза се уноси број рачунара n (1≤n≤50000), затим број парова рачунара који се могу повезати каблом m (n−1≤m≤n(n−1)/2, m≤105) 
и у наредних m редова подаци о рачунарима који се могу повезати 
(у сваком реду се налазе два цела броја која представљају редне бројеве рачунара, 
при чему се рачунари броје од нуле, и један реалан број који представља растојање између та два рачунара).

Излаз
На стандардни излаз исписати само један реалан број заокружен на једну децималу, који представља најмању укупну дужину каблова.

Primov algoritam je slican Dajkstrinom. 
Postoji skup cvorova Vk i min. povezujuce stablo tog skupa. 

1 Initialize a tree with a single vertex, chosen arbitrarily from the graph.
2 Grow the tree by one edge: 
of the edges that connect the tree to vertices not yet in the tree, find the minimum-weight edge, and transfer it to the tree.
3 Repeat step 2 (until all vertices are in the tree).

Скуп се проширује најкраћом граном која повезује неки чвор графа који припада скупу Vk и неки чвор графа који не припада скупу Vk. 
Razlika sa Dajkstrom je sto se ne razmatraju potencijalni cvorovi samo od pocetnog, nego od celog skupa Vk. 
Kad se dodaje novi cvor skupu Vk, azuriraju se samo rastojanja susedanovog cvora, ostala se ne menjaju. */

int main() {
    ios_base::sync_with_stdio(false); //
    int n; cin >> n;
    vector<vector<pair<double, int>>> veze(n);
    int e; cin >> e;
    for (int i = 0; i < e; i++)  {
        int u, v; double duz; cin >> u >> v >> duz;
        veze[u].emplace_back(duz, v);
        veze[v].emplace_back(duz, u);   }

    double res = 0.0;  // ukupna duz kablova u trenutnom stablu
    vector<double> rastojanje(n, INF); // najmanje rastojanje svakog cvora od trenutnog stabla
    vector<bool> pripada(n, false);  // da li je cvor u stablu?
    // polazi se od praznog stabla, a svaki cvor treba da bude ukljucen u stablo
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq; //
    rastojanje[0] = 0.0; // prvi je cvor 0, rastojanje je 0.0, da bi prvi bio prvi ukljucen
    pq.emplace(0.0, 0); //

    int br = 0; // u pocetku nema cvorova u stablu

    while (br < n) { // dok ne bude n cvorova u stablu...
        // pronalazimo cvor koji je najblizi trenutnom stablu koriscenjem reda i uklanjamo ga iz reda
        double najr; int najc;
        tie(najr, najc) = pq.top();
        pq.pop();
        // zbog lenjog brisanja, moguce je da je on ranije ukljucen u stablo, pa ga u tom slucaju zanemarujemo
        if (pripada[najc]) continue;
        
        pripada[najc] = true; // ukljucujemo najc u stablo
        br++;
        
        res += najr; // uracunavamo duzinu najkrace grane koja ga spaja sa trenutnim stablom
        
        rastojanje[najc] = 0.0; // njegovo rastojanje do stabla je sada 0
        
        for (auto v : veze[najc]) // razmatramo sve susede  cvoraMin
        // azuriramo njihovo rastojanje od trenutnog stabla, ako je to potrebno
            if (v.first < rastojanje[v.second]) {
                rastojanje[v.second] = v.first;
                // ako se rastojanje smanjilo, dodajemo ga u red, pri cemu
                // staru vrednost iz reda (ako postoji) ne brisemo odmah
                pq.push(v);    }     }

    cout << fixed << showpoint << setprecision(1) << res << endl;
    return 0; }