#include <iostream>
#include <queue>
using namespace std;
int main() {
    int arr[] = { 10, 2, 4, 8, 6, 9 };
    priority_queue<int> pq;

    for (int i = 0; i < 6; i++) 
        pq.push(arr[i]);

    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop(); } //10 9 8 6 4 2

//PQ je po difoltu max heap, ali to može da se promeni...

    priority_queue<int, vector<int>, greater<int>> pq2;
    cout << '\n';

    for (int i = 0; i < 6; i++) 
          pq2.push(arr[i]);

    while (!pq2.empty()) {
          cout << pq2.top() << ' ';
          pq2.pop(); } // 2 4 6 8 9 10 

    priority_queue<int, vector<int>, less<int>> pq3;
    cout << '\n';
    
    for (int i = 0; i < 6; i++) 
          pq3.push(arr[i]);
    while (!pq3.empty()) {
          cout << pq3.top() << ' ';
          pq3.pop(); } //10 9 8 6 4 2                     
    return 0; }