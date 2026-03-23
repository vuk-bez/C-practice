#include <stdio.h>
#include <stdlib.h>
// u ovom fajlu prezentovane su liste u C jeziku i metode sa njima
// karakteristike liste: linearne, nehomogene, dinamicke, ulancana memorijska reprezentacija

typedef struct Cvor{ //jednoulancana lista (sadrzi noseci podatak -- u ovom slucaju int info -- i pointer na sljedeci cvor)
    int info;
    struct Cvor *next;
} Cvor;

void umetniNakon(Cvor *p, int x) {
    Cvor *q = (struct Cvor*)malloc(sizeof(struct Cvor)); //logicki getnode
    q->info = x; // info cvora novog stavljamo na x
    q->next = p->next; //ono sto je prije pointao p sada stavljamo u q
    p->next = q; // a p sada pointa na q
}

void obrisiNakon(Cvor *p) {
    if(p->next != NULL) {
        Cvor *q = p->next; // setamo do cvora q koji treba izbrisat
        p->next = q->next; // stavljamo da p.next pokazuje na ono sto je posle q
        free(q); //brisemo q
    }

}

Cvor* pretrazi(Cvor* glava, int x) {
    Cvor *p = glava; //nalazimo prvi clan liste preko pointera iz argumenta
    while(p != NULL && p->info != x) { // sve dok pokazivac nije NULL ili dok vrijednost cvora nije x
        p = p->next; // pointer postaje sljedeci pointer u listi
    }
    return p;
}

void stampaListe(Cvor* glava) {
    Cvor *temp = glava; //u privremeni pointer postavljamo pointer za cvor GLAVA
    while(temp != NULL) { // sve dok pokazivac nije NULL
        printf("%d -> ", temp->info); //ostampaj ono sto je sacuvano u cvoru na koji pokazuje trenutni pointer
        temp = temp->next; //pomjeri pointer na sljedeci cvor
    }
    printf("NULL \n");
}

void brisanjeListe(Cvor* glava) {
    Cvor* temp = glava; 
    while(temp != NULL) {
        Cvor* sljedeci = temp->next;
        free(temp);
        temp = sljedeci;
    }
}


int main() {

    Cvor *glava = NULL;
    Cvor *jedan = NULL;
    Cvor *dva = NULL;

    // Alocirajmo memoriju potrebnu za cvorove
    glava = (struct Cvor*)malloc(sizeof(struct Cvor));
    jedan = (struct Cvor*)malloc(sizeof(struct Cvor));
    dva = (struct Cvor*)malloc(sizeof(struct Cvor));

    // Postavljamo vrijednosti u cvorovima
    glava->info = 10;
    glava->next = jedan;

    jedan->info = 20;
    jedan->next = dva;

    dva->info = 30;
    dva->next = NULL; 

    umetniNakon(jedan, 67);

    stampaListe(glava);
    brisanjeListe(glava);

    return 0;
}