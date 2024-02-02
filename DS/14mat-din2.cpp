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
    for (int s = 0; s < n; s++) { // računa sve proseke ocena
        int zbir = 0;
        int broc = ocene[s].size(); // br. ocena za svakog
        for (int o = 0; o < broc; o++)
            zbir += ocene[s][o];
        cout << (double) zbir / (double) broc << endl; } // ispis
    return 0; }
