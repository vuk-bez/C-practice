#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cilj zadatka jeste napraviti program koji prati narudzbe u jednom restoranu
//U ovom primjeru koristicemo ulancane liste, jer je jasno da ce broj dodavanja i brisanja
//biti velik. Zbog toga su liste pogodnije od nizove jer one u tim procedurama imaju O(1)
//za razliku od nizova cija je slozenost O(n)

typedef struct Narudzba { //definisemo prvo cvor 
    int id;
    char imeKupca[50];
    float ukupnaCijena;
    struct Narudzba* next;
} Narudzba;

void dodajNarudzbu(Narudzba ** glava, char* Kupac, float cijena) {
    // alociramo memoriju za novi cvor i upisujemo podatke
    Narudzba* nova = (Narudzba*)malloc(sizeof(Narudzba));
    nova->ukupnaCijena = cijena;
    strcpy(nova->imeKupca, Kupac);
    nova->next = NULL;

    //ako je lista prazna, tj unosi se prvi clan
    if(*glava == NULL) {
        nova->id = 1;
        *glava = nova;
        return;
    }

    //prolazak kroz listu, ako vec imamo neke clanove
    Narudzba* trenutni = *glava;
    while(trenutni->next != NULL) {
        trenutni = trenutni->next;
    }
    nova->id = trenutni->id +1;
    trenutni->next = nova;

}

void stampajNarudzbe(Narudzba* glava) {
    Narudzba* trenutni = glava;
    if(glava == NULL) {
        printf("Nema narudzbi.\n");
        return;
    }
    while(trenutni != NULL) {
        printf("ID: %d | Customer: %s | Total: %.2f EUR \n", trenutni->id, trenutni->imeKupca, trenutni->ukupnaCijena);
        trenutni = trenutni->next;
    }
}

Narudzba* pronadjiNarudzbu(Narudzba* glava, int id) {
    Narudzba* trenutni = glava;
    int pronasao = 0;

    while(trenutni != NULL) {
        if(trenutni->id == id) {
            pronasao = 1;
            break;
        }
        trenutni = trenutni->next;
    }

    if(trenutni) {
        return trenutni;
    } else {
        trenutni = NULL;
        return trenutni;
    }
}

void oslobodiListu(Narudzba* glava) {

    Narudzba* temp;

    while(glava != NULL) {
        temp = glava;
        glava = glava->next;
        free(temp);
    }

    printf("Lista oslobodjena.\n");
}

void obrisiNarudzbu(Narudzba** glava, int id) {

    if (*glava == NULL) {
        printf("Lista je prazna.\n");
        return;
    }

    Narudzba* trenutni = *glava;
    Narudzba* prethodni = NULL;

    while (trenutni != NULL && trenutni->id != id) {
        prethodni = trenutni;
        trenutni = trenutni->next;
    }

    if (trenutni == NULL) {
        printf("Narudzba sa ID %d nije pronadjena.\n", id);
        return;
    }

    if (prethodni == NULL) {
        *glava = trenutni->next;
    }
    else {
        prethodni->next = trenutni->next;
    }

    free(trenutni);

    printf("Narudzba sa ID %d je obrisana.\n", id);
}

int main () {

    Narudzba* glava = NULL;

    dodajNarudzbu(&glava, "Vuk Bezma", 25.50);
    dodajNarudzbu(&glava, "Batriiiii", 13.20);
    dodajNarudzbu(&glava, "Maksim Karadzic", 42.00);
    dodajNarudzbu(&glava, "Milos Markovic", 18.75);

    stampajNarudzbe(glava);

    // pretraga
    Narudzba* pronadjena = pronadjiNarudzbu(glava, 2);

    if(pronadjena != NULL) {
        printf("Pronadjena: %s | %.2f EUR\n", pronadjena->imeKupca, pronadjena->ukupnaCijena);
    } else {
        printf("Narudzba nije pronadjena.\n");
    }


    oslobodiListu(glava);
    return 0;
}