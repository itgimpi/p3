#include<stdio.h>
// Logicki operatori
int main(){
    int x = 2, y = 5; // x je true, y je true.
    // true je razlicito od 0, false je 0
    printf("%d %d\n", !x, !y); // negacija, ne
    printf("%d\n", x && y); // konjukcija, i
    printf("%d\n", x || y); // disjunkcija, ili
/*
0 0 negacije od T su F
1, T i T
1, T ili T
*/
   // istinitosne tablice
    int p, q;
    for ( p = 0; p < 2; p++)
        printf("ne od  %d je  %d\n", p, !p );

    for ( p = 0; p < 2; p++) // za svako p F, T
            for ( q = 0; q < 2; q++) {  // za svako q F, T
                printf("%d i %d je %d\n", p, q, p && q );
                printf("%d ili %d je %d\n", p, q, p || q ); }

    return 0;
}