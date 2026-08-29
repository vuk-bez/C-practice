#include <stdio.h>
// implementacija je odradjena preko binarnog hipa

int popunjenost = 0;
void insert(int niz[], int n, int x) {
    if(popunjenost == n) {
        printf("Red je pun");
        return;
    }
    int sin = popunjenost;
    int otac = (popunjenost-1)/2;
    niz[popunjenost] = x;
    popunjenost++;
    while (otac >= 0) {
        if (niz[otac] < niz[sin]) {
            int temp = niz[otac];
            niz[otac] = niz[sin];
            niz[sin] = temp;
        } else {
            break;
        }
        sin = otac;
        otac = (otac-1)/2;
    } 
}

int delete(int niz[], int n) {
    if (popunjenost == 0) {
        printf("Red je prazan");
        return -1;
    }
    int top = niz[0];
    niz[0] = niz[popunjenost-1];
    int otac = 0;
    int sin = 1;
    popunjenost--;
    while (sin < popunjenost) {
        if (sin + 1 < popunjenost && niz[sin] < niz[sin+1]) {
            sin = sin + 1;
        }
        if (niz[otac] < niz[sin]) {
            int temp = niz[otac];
            niz[otac] = niz[sin];
            niz[sin] = temp;
        } else {
            break;
        }
        otac = sin;
        sin = 2*sin + 1;
    }

    return top;
}

void stampa(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
}

int main() {
    int queue[100];
    insert(queue, 100, 5);
    insert(queue, 100, 33);
    insert(queue, 100, 10);
    insert(queue, 100, 21);
    insert(queue, 100, 58);
    stampa(queue, popunjenost);
    printf("\n");
    delete(queue, popunjenost);
    stampa(queue, popunjenost);
    return 0;
}