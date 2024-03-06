#include<stdio.h>
// Brojevni sistemi, C, binarni, oktalni, dekadni, heksadekadni
int main(){
    // deka- broj moze da se konvertuje u okta, heksadeka
    char c = 48; // ASCII kod za 0, dekadno
    printf("znak %c, deka %d\n", c, c); // znakovni i deka- ispis
    printf("okta %o, heksa %x\n", c, c); // okta- i heksa- ispis

    char cc = 47; // dekadno
    printf("znak %c, deka %d\n", cc, cc); // znakovni i deka- ispis
    printf("okta %o, heksa %x, heksa2 %X\n", cc, cc, cc); // okta- i heksa- ispis

// konverzija iz nekog br. sistema u deka-
    int h = 0x2f; // heksa
    int o = 057;// okta
    int b = 0b00101111;
    printf("%d %d %d\n", h, o, b);
    return 0;
}