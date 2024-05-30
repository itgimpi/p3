#include<bits/stdc++.h>
using namespace std; 

void encode(string &s, int pom) {
    for (int i = 0; i < s.size(); i++) {
        int rb = s[i] - 'a';
        int rbsp = rb + pom;
        int rbspmod = rbsp % 26;
        s[i] = 'a' + rbspmod;  } }

void decode(string &s, int pom) {
    for (int i = 0; i < s.size(); i++) {
        int rb = s[i] - 'a';
        int rbsp = rb - pom + 26;
        int rbspmod = rbsp % 26;
        s[i] = 'a' + rbspmod;  } }

int main() {
    string s; cin >> s;
    int pom; cin >> pom;
    encode(s, pom);
    cout << s;



}