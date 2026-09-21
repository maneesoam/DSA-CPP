#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int a[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(a[r], a[high]);          // random pivot

    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(a[j] < pivot)
            swap(a[++i], a[j]);
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[] = {8, 3, 7, 4, 9, 2, 6};
    int n = 7;

    quickSort(a, 0, n - 1);

    for(int x : a)
        cout << x << " ";
}