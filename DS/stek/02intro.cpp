#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string> languages; // create a stack of strings
    languages.push("C++"); // add element to the Stack
    languages.push("Java");
    languages.push("Python");
    cout << languages.top(); // print top element
    return 0; }
