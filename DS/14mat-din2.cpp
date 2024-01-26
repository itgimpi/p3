#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<vector<int>> ocene(n);
    for (int s = 0; s < n; s++) { // ocene svih studenata
        int br; cin >> br; // broj ocena za svakog studenta
        ocene[s].resize(br);
        for (int oc = 0; oc < br; oc++)
            cin >> ocene[s][oc]; }
    for (int u = 0; u < n; u++) { // računa sve proseke ocena
        int zbir = 0;
        int broc = ocene[u].size(); // br. ocena za svakog
        for (int o = 0; o < broc; o++)
            zbir += ocene[u][o];
        cout << (double) zbir / (double) broc << endl; } // ispis
    return 0; }
