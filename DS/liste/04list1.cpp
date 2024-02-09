#include <bits/stdc++.h>
using namespace std;
// Lists in C++ using global pointer

class node {
public:
    int data; // 4B
    struct node *next; } ; // 8B

node *head = nullptr; // globalna promenljiva

void dodaj(int podatak) { // ispred prvog elementa
    node *novi = new node; // alociraj mem. za novi cvor
    novi->data = podatak; // upisi kor. pod.
    novi->next = head; // 1. novi pokazuje na preth. prvi tj. hed
    head = novi;} // hed na novi

void izbaci( ) {
    if ( head == nullptr ) // empty list?
        return; 
    node *tmp = head;
    head = head->next;
    delete tmp; }

void ispis(node *n) { // n pokazuje na pocetak
    while ( n != nullptr ) { // sve dok ne stigne do kraja...
        cout << n->data << ' '; // ispis
        n = n->next; } // n pokazuje na sledeci
    cout << endl; }

int main() {

    dodaj(1); ispis(head); // pointer to pointer, adresa adrese
    dodaj(2); ispis(head); 
    dodaj(3); ispis(head); 
    izbaci(); ispis(head);


    return 0; }
