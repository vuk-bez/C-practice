#include <stdio.h>

void adjust(int niz[], int i, int n) {
    int K = niz[i];
    int j = 2*i + 1;
    while (j < n) {
        if ((j+1 < n) && (niz[j] < niz[j+1])) {
            j = j + 1;
        }
        if (K >= niz[j]) {
            niz[(j - 1) / 2] = K;
            return; 
        } else {
            niz[(j - 1) / 2] = niz[j];
            j = 2*j + 1;
        }
        niz[(j - 1) / 2] = K;
    }

}

void sort(int niz[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        adjust(niz, i, n);
    }
    for (int i = n-1; i > 0; i--) {
        int temp = niz[0];
        niz[0] = niz[i];
        niz[i] = temp;
        adjust(niz, 0, i);
    }
}

void stampa(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
}

int main () {

    int a[] = {22, 11, 38, 5, 29, 40, 41};
    int n = 7;

    sort(a, n);
    stampa(a, n);
    printf("\n");
    stampa(a, n);

    return 0;
}