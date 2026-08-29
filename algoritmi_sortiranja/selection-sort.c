#include <stdio.h>

// Metod selekcije 
// Vremenska slozenost O(n^2)
void sortAsc(int niz[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = niz[i];
        int pos = i;
        for (int j = i+1; j < n; j++) {
            if(niz[j] < min) {
                min = niz[j];
                pos = j;
            }
        }
        niz[pos] = niz[i];
        niz[i] = min; 
    }
}

void sortDesc(int niz[], int n) {
    for(int i = 0; i < n-1; i++) {
        int max = niz[i];
        int pos = i;
        for (int j = i+1; j < n; j++) {
            if(niz[j] > max) {
                max = niz[j];
                pos = j;
            }
        }
        niz[pos] = niz[i];
        niz[i] = max; 
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