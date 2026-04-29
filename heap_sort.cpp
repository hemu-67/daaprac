#include <iostream>
using namespace std;

int comp = 0;

void heapify(int a[], int n, int rootIndex) {
    int largest = rootIndex;
    int left_child = 2 * rootIndex + 1;
    int right_child = 2 * rootIndex + 2;

    if(left_child < n && (++comp && a[left_child] > a[largest])) 
        largest = left_child;

    if(right_child < n && (++comp && a[right_child] > a[largest])) 
        largest = right_child;

    if(largest != rootIndex) {
        swap(a[rootIndex], a[largest]);
        heapify(a, n, largest);
    }
}

int main() {
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    // Build heap
    for(int rootIndex = n/2 - 1; rootIndex >= 0; rootIndex--) 
        heapify(a, n, rootIndex);

    // Heap sort
    for(int rootIndex = n - 1; rootIndex > 0; rootIndex--) {
        swap(a[0], a[rootIndex]);
        heapify(a, rootIndex, 0);
    }

    for(int i = 0; i < n; i++) 
        cout << a[i] << " ";

    cout << "\nComparisons: " << comp;
}
