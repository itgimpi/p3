#include <bits/stdc++.h>
using namespace std;
// Lists in C++ using pointers to pointers from main 

class node {
public:
    int data; // 4B
    struct node *next; } ; // 8B

void dodaj(node **glava, int podatak) { // ispred prvog elementa
    node *novi = new node; // alociraj mem. za novi cvor
    novi->data = podatak; // upisi kor. pod.
    novi->next = *glava; // 1. novi pokazuje na preth. prvi tj. hed
    *glava = novi;} // hed na novi

void izbaci( node **glava ) {
    if ( *glava == nullptr ) // empty list?
        return; 
    node *tmp = *glava;
    *glava = (*glava)->next;
    delete tmp; }

void ispis(node *n) { // n pokazuje na pocetak
    while ( n != nullptr ) { // sve dok ne stigne do kraja...
        cout << n->data << ' '; // ispis
        n = n->next; } // n pokazuje na sledeci
    cout << endl; }

int main() {
    node *head = nullptr;
    //dodaj(head, 1); head ne moze da se azurira
    dodaj(&head, 1); ispis(head); // pointer to pointer, adresa adrese
    dodaj(&head, 2); ispis(head); 
    dodaj(&head, 3); ispis(head); 
    izbaci(&head); ispis(head);


    return 0; }
