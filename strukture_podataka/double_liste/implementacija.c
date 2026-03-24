#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor {
    int info;
    struct Cvor* next;
    struct Cvor* prev;
} Cvor;

void dodajNaPocetak(Cvor* glava, Cvor* rep, int info) {
    Cvor* novi = (Cvor*)malloc(sizeof(Cvor));

    if (glava == NULL) {
        glava = novi;
        rep = novi;
    } else {

    }


}

int main() {

    Cvor* glava = NULL;
    Cvor* rep = NULL;

    return 0;
}