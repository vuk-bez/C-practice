#include <stdio.h>

// Metod umetanja - O(n^2)
void sortDesc(int niz[], int n) {
    for (int i = 1; i < n; i++) {
        int K = niz[i];
        int j = i-1;

        while(j >= 0 && K > niz[j]) {
            niz[j+1] = niz[j]; j --;
        }
        niz[j+1] = K;
    }
}

void sortAsc(int niz[], int n) {
    for (int i = 1; i < n; i++) {
        int K = niz[i];
        int j = i-1;

        while(j >= 0 && K < niz[j]) {
            niz[j+1] = niz[j]; j --;
        }
        niz[j+1] = K;
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

    sortDesc(a, n);
    stampa(a, n);
    printf("\n");
    sortAsc(a, n);
    stampa(a, n);

    return 0;
}