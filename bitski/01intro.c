#include<stdio.h>
// Logicki operatori (npr &&) nisu isto sto i bitski (&) 
int main(){
    int x = 2, y = 5; // x je true, y je true.
    // true je razlicito od 0, false je 0
    printf("%d\n", x && y); // konjukcija, T i T je T
    printf("%d\n", x & y); // bitska konjukcija, 010 bit po bit i 101 je 000 

    printf("%d\n", x || y); // disjukcija, T ili T je T
    printf("%d\n", x | y); // konjukcija, 010 bit po bit 101 je 111 a to je 7


    return 0;
}