#include <iostream>
#include <vector> //vektor - uvodni primer
using namespace std; 
int main() {
    vector<int> a {1, 2, 3, 4, 5 };
    vector<int> b(5);
    b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4; b[4] = 5;
    vector<int> c;
    c.push_back(1); c.push_back(2); c.push_back(3); c.push_back(4); c.push_back(5);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' '; cout << endl;
    a.resize(3);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' '; cout << endl;
    a.resize(10, 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' '; cout << endl;
    for (auto bb : b)
        cout << bb << ' '; cout << endl;
    for (auto it = b.begin(); it < b.end(); it++)
        cout << *it << ' '; cout << endl; 
    while (!c.empty()){
        cout << c.back() << ' '; 
        c.pop_back(); } 
    cout << endl;
    return 0; }
