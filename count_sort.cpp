#include <iostream>
using namespace std;

int main() {
    int n,a[100],count[100]={0},max=0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i]>max) max=a[i];
    }

    for(int i=0;i<n;i++) count[a[i]]++;

    for(int i=0;i<=max;i++)
        while(count[i]--) cout<<i<<" ";
}
