#include <iostream>
using namespace std;

int comp = 0;

void merge(int a[], int start, int mid, int end) {
    int left = start, right = mid + 1;
    int index = 0;
    int temp[100];

    while(left <= mid && right <= end) {
        comp++;
        if(a[left] <= a[right]) {
            temp[index++] = a[left++];
        } else {
            temp[index++] = a[right++];
        }
    }

    while(left <= mid) {
        temp[index++] = a[left++];
    }

    while(right <= end) {
        temp[index++] = a[right++];
    }

    for(int i = start, j = 0; i <= end; i++, j++) {
        a[i] = temp[j];
    }
}

void mergeSort(int a[], int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

int main() {
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "\nSorted array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";

    cout << "\nComparisons: " << comp;
}
