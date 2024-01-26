#include <iostream>
using namespace std;

int main() {
    int A[5][5];
    for (int v = 0; v < 5; v++) // učitava matricu
        for (int k = 0; k < 5; k++)
            cin >> A[v][k];
    int trag = 0; // izračunava i ispisuje trag
    for (int i = 0; i < 5; i++)
        trag += A[i][i];
    cout << trag << endl;
    return 0; }
