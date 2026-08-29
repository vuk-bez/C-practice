#include <stdio.h>

int partition (int niz[], int n, int up, int down) {
    int i = down;
    int j = up;
    int pivot = niz[down];
    while (i < j) {
        while (niz[i] <= pivot && i < j) {
            i ++;
        }
        while (niz[j] > pivot) {
            j --;
        } 
        if (i < j) {
            int temp = niz[i];
            niz[i] = niz[j];
            niz[j] = temp;
        }
    }
    niz[down] = niz[j];
    niz[j] = pivot;
    return j;
} 

void sort(int niz[], int n, int low, int high) {
    if (low >= high) {
    return;
    }   
    int j = partition(niz, n, high, low);
    sort(niz, n, low, j - 1);
    sort(niz, n, j + 1, high);
}

void stampa(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
}

int main () {

    int a[] = {22, 11, 38, 5, 29, 40, 41};
    int n = 7;

    sort(a, n, 0, n-1);
    stampa(a, n);
    printf("\n");
    stampa(a, n);

    return 0;
}