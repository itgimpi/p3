#include <bits/stdc++.h>
using namespace std;

vector<int> heap;
int roditelj(int i){return (i-1)/2;}

void heapify_up(int value){
    heap.push_back(value);
    int index = heap.size()-1;
    while(index != 0 && heap[index]>heap[roditelj(index)]){
        swap(heap[index],heap[roditelj(index)]);
        index = roditelj(index);
    }
}
int main(){
    heapify_up(80);
    heapify_up(75);
    heapify_up(61);
    heapify_up(70);
    heapify_up(43);
    heapify_up(32);
    heapify_up(34);
    heapify_up(76);

    for(int i = 0; i < heap.size();i++){
        cout << heap[i] << ' ';
    }
}