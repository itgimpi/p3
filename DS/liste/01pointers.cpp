#include <bits/stdc++.h>
using namespace std;
// Pointers, Lists in C++

class node {
public:
    int data; // 4B
    struct node *next; } ; // 8B

int main() {
    node *head = nullptr; // NULL, 0
    node *second = nullptr;
    node *third = nullptr;

    head = new node; // 12
    second = new node; // 12
    third = new node; // 12

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;   

    third->data = 3;
    third->next = nullptr; 

    // ispis liste...

    return 0; }
