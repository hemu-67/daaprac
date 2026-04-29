#include <iostream>
using namespace std;

int comp = 0;

int partition(int a[], int low, int high) {
    int pivot = a[high], i = low-1;

    for(int j=low;j<high;j++) {
        comp++;
        if(a[j] < pivot) {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = partition(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main() {
    int n,a[100];
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];

    quickSort(a,0,n-1);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\nComparisons: "<<comp;
}
