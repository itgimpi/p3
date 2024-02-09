#include <bits/stdc++.h>
using namespace std;
// Lists in C++ using non-void functions

class node {
public:
    int data; // 4B
    struct node *next; } ; // 8B

node * dodaj(node *glava, int podatak) { // ispred prvog elementa
    node *novi = new node; // alociraj mem. za novi cvor
    novi->data = podatak; // upisi kor. pod.
    novi->next = glava; // 1. novi pokazuje na preth. prvi tj. hed
    return novi;} // hed na novi

node * izbaci(node *glava) {
    if ( glava == nullptr ) // empty list?
        return glava; // nullptr
    // not empty...
    node * tmp = glava; // zapamti cvor za izbacivanje
    glava = glava->next;
    delete tmp; 
    return glava; }

void ispis(node *n) { // n pokazuje na pocetak
    while ( n != nullptr ) { // sve dok ne stigne do kraja...
        cout << n->data << ' '; // ispis
        n = n->next; } // n pokazuje na sledeci
    cout << endl; }

int main() {
    node *head = nullptr; // head trenutno ne pokazuje na nista
    head = dodaj(head, 1); ispis(head); // u head ide rezultat f-je
    head = dodaj(head, 2); ispis(head); 
    head = dodaj(head, 3); ispis(head); 
    
    head = izbaci(head); ispis(head);


    return 0; }
