#include<stdio.h>
#include <string.h>
int main() {
    char s1[] = {'S', 't', 'r', 'i', 'n', 'g'}; // NE VALJA
    char s2[] = {'S', 't', 'r', 'i', 'n', 'g', '\0'}; // VALJA
    char s[] = "String"; 


    printf("%s\n", s);
    printf("%i\n", strlen(s));


}