#include <bits/stdc++.h>
using namespace std;
// Pointers, Lists in C 

struct Node {
    int data; // 4B
    struct Node *next; } ; // 8B

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = ( struct Node * ) malloc( sizeof( struct Node ) ); // 12
    second = ( struct Node * ) malloc( sizeof( struct Node ) ); // 12
    third = ( struct Node * ) malloc( sizeof( struct Node ) ); // 12

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;   

    third->data = 3;
    third->next = NULL; 

    // ispis liste...

    return 0; }
