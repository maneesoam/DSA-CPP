#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int h) {
    int i=l, j=m+1, k=l, c[10];

    while(i<=m && j<=h) {
        if(a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while(i<=m) c[k++] = a[i++];
    while(j<=h) c[k++] = a[j++];

    for(i=l; i<=h; i++)
        a[i] = c[i];
}

void mergesort(int a[], int l, int h) {
    if(l < h) {
        int m = (l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}

int main() {
    int a[10], n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];

    mergesort(a,0,n-1);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    return 0;
}
