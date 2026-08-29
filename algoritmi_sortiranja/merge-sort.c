#include <stdio.h>
int c[5];

void merge(int a[], int la, int ha, int b[], int lb, int hb, int c[], int lc) {
    int i = la;
    int j = lb;
    int k = lc;
    while (i <= ha && j <= hb) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if (i > ha) {
        while (j <= hb) {
            c[k] = b[j];
            j++;
            k++;
        }
    } else {
        while (i <= ha) {
            c[k] = a[i];
            i++;
            k++;
        }
    }
}

void sort(int niz[], int h, int l) {
    if (l < h) {
        int mid = (h-l)/2;
        sort(niz, mid, l);
        sort(niz, h, mid+1);
        merge(niz, l, mid, niz, mid+1, h, c, 1);
        for (int i = l; i <= h; i++) {
            niz[i] = c[i-l+1];
        }
    }
}

int main() {
    int niz[5] = {1 , 19, 2, -10, 35};
    
    return 0;
}