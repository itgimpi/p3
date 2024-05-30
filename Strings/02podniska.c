#include<stdio.h>
#include <string.h>

int seno( char *igla, char plast[]) {
    int np = strlen(plast);
    int ni = strlen(igla);

    for ( int ip = 0; ip + ni <= np; ip++ ) {
        int isti = 1;
        for ( int ii = 0; ii < ni; ii++ ) {
            if ( plast[ip+ii] != igla[ii] ) {
                isti = 0;
                break;  } }
        if (isti) return ip; }
    return -1; }

int main() {
    char igla[1000], plast[1000];
    scanf("%s %s", plast, igla);
    //printf("%i", seno(igla, plast));
    
    char *poz = strstr(plast, igla);
    if ( poz != NULL ) printf("%d", poz - plast);
    else printf("-1");

}