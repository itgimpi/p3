#include <iostream>
#include <queue>
using namespace std;
int main() { 
    queue<int> q;
    q.push(1); q.push(2); q.push(3); 
    cout << q.size() << endl;
    cout << q.front() << " " << q.back() << endl;
    
    q.pop(); cout << q.front() << " " << q.back() << endl;
    q.pop(); cout << q.front() << " " << q.back() << endl;
    q.pop(); //cout << s.top() << endl;     
    q.push(1); q.push(2); q.push(3);
    while (!q.empty()) { 
        cout << q.front() << " " << q.back() << endl; 
        q.pop(); } } 
