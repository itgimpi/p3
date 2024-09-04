#include <bits/stdc++.h> 
using namespace std;      

vector<int> heap;   // Vector to store heap elements

    // Function to get the parent index
int parent(int i) { return (i - 1) / 2; }
    // Function to get the left child index
int leftChild(int i) { return 2 * i + 1; }
    // Function to get the right child index
int rightChild(int i) { return 2 * i + 2; }


    // Function to maintain the heap property while moving up
void heapifyUp(int index) {
        // Continue until reaching the root or heap property is satisfied
    while (index != 0 && heap[parent(index)] < heap[index]) {
        swap(heap[index], heap[parent(index)]);  // Swap current element with its parent
        index = parent(index);  // Move to the parent's index
        }
    }

    // Function to maintain the heap property while moving down
void heapifyDown(int index) {
    int largest = index;  // Initialize largest as root
    int left = leftChild(index);  // Left child index
    int right = rightChild(index);  // Right child index

        // If left child is larger than root
    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;

        // If right child is larger than largest so far
    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

        // If largest is not root
    if (largest != index) {
        swap(heap[index], heap[largest]);  // Swap root with largest
        heapifyDown(largest);  // Recursively heapify the affected sub-tree
        }
    }




    // Function to insert a new value into the heap
void insert(int value) {
    heap.push_back(value);  // Add the new value at the end
    heapifyUp(heap.size() - 1);  // Restore the heap property
    }

    // Function to delete the root of the heap
void deleteRoot() {
    if (heap.empty()) return;  // If heap is empty, do nothing
    heap[0] = heap.back();  // Replace root with the last element
    heap.pop_back();  // Remove the last element
    heapifyDown(0);  // Restore the heap property
    }

    // Function to print the heap
void printHeap() {
    for (int val : heap) {
        cout << val << " ";  // Print each value
        }
    cout << endl;  // Newline for clarity
    }


int main() {
      
    insert(10);  // Insert values into the max-heap
    insert(5);
    insert(30);
    insert(20);
    insert(35);

    cout << "Max-Heap array: ";
    printHeap();  // Print the heap

    deleteRoot();  // Delete the root of the heap
    cout << "After deleting root: ";
    printHeap();  // Print the heap again

    return 0;
}