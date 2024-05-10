#include<stdio.h>
#include <string.h>

int main() {
    char ime[100], pre[100];
    while ( scanf("%s %s", ime, pre) == 2 ) {
        printf("%s %s\n", pre, ime); }
}