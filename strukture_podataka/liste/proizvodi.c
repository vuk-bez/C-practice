#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Proizvod {
    int id;
    char naziv[50];
    int kolicina;
    float cijena;
    struct Proizvod* next;
} Proizvod;

void dodajProizvod(Proizvod** glava, char* naziv, int kolicina, float cijena) {
    Proizvod* trenutni = *glava;
    
    if(trenutni == NULL) {
        Proizvod* novi = (Proizvod*)malloc(sizeof(Proizvod));
        *glava = novi;
        novi->id = 1;
        strcpy(novi->naziv, naziv);
        novi->kolicina = kolicina;
        novi->cijena = cijena;
        return;
    }

    while(trenutni->next != NULL) {
        if(strcmp(trenutni->naziv, naziv) == 0) {
            trenutni->kolicina += kolicina;
            return;
        }
        trenutni = trenutni->next;
    }
        Proizvod* novi = (Proizvod*)malloc(sizeof(struct Proizvod));
        trenutni->next = novi;
        novi->id = trenutni->id + 1;
        strcpy(novi->naziv, naziv);
        novi->kolicina = kolicina;
        novi->cijena = cijena;
    
}

void ispisInventara(Proizvod* glava) {
    Proizvod* trenutni = glava;
    
    if(trenutni == NULL) {
        printf("Inventar je prazan. \n");
        return;
    }
    
    while(trenutni != NULL) {
        printf("ID: %d | Naziv: %s | Kolicina: %d | Cijena: %.2f EUR \n", trenutni->id, trenutni->naziv, trenutni->kolicina, trenutni->cijena);
        trenutni = trenutni->next;
    }
    printf("\n");
}

Proizvod* pronadjiProizvod(Proizvod* glava, char* naziv) {
    Proizvod* trenutni = glava;
    while(trenutni != NULL) {
        if(strcmp(trenutni->naziv, naziv) == 0) {
            return trenutni;
        }
        trenutni = trenutni->next;
    }
    return trenutni;
}

int main() {

    return 0;
}