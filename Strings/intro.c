#include<stdio.h>
#include <string.h>

int strlen2(char s[]){
    int i = 0;
    while ( s[i] != '\0' ) 
        i++;
    return i; }






int strlen3(char s[]){
    int i = 0;
    for ( ; s[i] != '\0'; i++ ) 
        ;
    return i; }

int strlen4(char *s){ // s[] = *s
    int i = 0;
    for ( ; *s != 0; s++ ) // 
        i++;
    return i; }

int strlen5(char *s){ // s[] = *s
    char *p = s;
    for ( ; *p != 0; p++ ) // 
        ;
    return p-s; }

int strlen6(char *s) { 
    char *p = s;
    for ( ; *p; p++ ) // basic C
        ;
    return p-s; } 

int strlen7(char *s) { 
    char *p = s;
    while ( *p ) // basic C
        p++;
    return p-s; }        

int main() {
    char s1[] = {'S', 't', 'r', 'i', 'n', 'g'}; // NE VALJA
    char s2[] = {'S', 't', 'r', 'i', 'n', 'g', '\0'};
    char s[] = "String"; // podrazumeva se i '\0'

    printf("%s\n", s);
    printf("%d\n", strlen(s)); // O(n)
    printf("%d\n", strlen2(s)); // O(n)
    printf("%d\n", strlen3(s)); // O(n)
    printf("%d\n", strlen4(s)); // O(n)
    printf("%d\n", strlen5(s)); // O(n)
    printf("%d\n", strlen6(s)); // O(n)
    printf("%d\n", strlen7(s)); // O(n)

}