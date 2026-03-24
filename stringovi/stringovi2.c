// zadaci iz fajla stringovi2.pdf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ZAD 2.
// Kapetan Flint je sakrio blago na tajanstvenom ostrvu, ali je ostavio opis kako ga naći. Opis se
// sastoji od stringova oblika "North 5", gdje je riječ jedna od "North", "South", "East",
// "West" i daje pravac kretanja, a broj daje koliko koraka treba napraviti u datom smjeru. Napišite
// program koji na osnovu datog opisa odreñuje tačne koordinate blaga, ako se koordinatni početak
// nalazi na početku puta, X-osa je usmjerena ka istoku a Y-osa ka sjeveru. Ulaz: Unose se stringovi u
// datom formatu. Brojevi ne prelaze 108. Izlaz: Štampati dva cijela broja razdvojena blankom –
// koordinate blaga.

void zad2() {
    int k;
    scanf("%d\n", &k);

    char s[100];

    int y;
    int x = y = 0;

    for (int i = 0; i < k; i++) {
        gets(s);
        printf("%s\n", s);
        char* razmak = strchr(s, ' ');
        char smjer[10];
        strncpy(smjer, s, razmak - s);
        smjer[razmak - s] = '\0';

        char d_str[10];
        strcpy(d_str, razmak+1);
        int d;
        sscanf(d_str, "%d", &d);

        if (strcmp(smjer, "North") == 0) {
            y += d;
        } else if (strcmp(smjer, "South") == 0) {
            y -= d;
        } else if (strcmp(smjer, "East") == 0) {
            x += d;
        } else if (strcmp(smjer, "West") == 0) {
            x -= d;
        } else {
            printf("Greska!\n");
        }
    }
}

// ZAD 3.
// Dozvoljena je sljedeća operacija: u riječi uzmemo prvi suglasnik i zamijenimo mjesta sa
// posljednjim suglasnikom; drugi suglasnik zamijeni mjesta sa pretposljednjim suglasnikom, itd. Ako
// poslije te operacije opet dobijemo polaznu riječ, tada takvu riječ nazivamo bezglasni palindrom (npr.
// takve su riječi sos, rare, rotor, gong, karaoke). Napisati program koji provjerava da li je data riječ
// bezglasni palindrom. Ulaz: Unosi se jedna riječ, dužine ne veće od 20, samo mala slova. Izlaz:
// Štampati YES ili NO

int jeSamoglasnik(char slovo) {
    return slovo == 'a' || slovo == 'e' || slovo == 'i' ||  slovo == 'o' || slovo == 'u';
}
void zad3() {
    char unos[100];
    char transform[100];

    scanf("%s", unos);
    int pocetak = 0;
    int kraj = strlen(unos) - 1;
    strcpy(transform, unos);

    while (pocetak < kraj) {
        if (!jeSamoglasnik(transform[pocetak])) {
            if (!jeSamoglasnik(transform[kraj])) {
                char temp = transform[pocetak];
                transform[pocetak] = transform[kraj];
                transform[kraj] = temp;

                pocetak++;
                kraj--;
            } else {
                kraj--;
            }
        } else {
            pocetak++;
        }
    }

    if (strcmp(unos, transform) == 0) printf("DA");
    else printf("NE");

}

// ZAD 4.
// Lozinka je jaka ako je njena dužina najmanje 8 simbola, i sadrži mala slova, velika slova i cifre.
// Napisati program koji provjerava da li je lozinka jaka. Ulaz: Unosi se jedna riječ, dužine ne veće od
// 100, koja sadrži mala i velika slova i cifre. Izlaz: Štampati YES ili NO

void zad4() {

    char unos[100];
    scanf("%s", unos);
    int velika = 0;
    int mala = 0;
    int karakteri = strlen(unos);
    int brojevi = 0;
    for (int i = 0; i < karakteri; i++) {
        if (unos[i] >= 'a' && unos[i] <= 'z') {
            mala++;
        } else if (unos[i] >= 'A' && unos[i] <= 'Z') {
            velika++;
        } else if (unos[i] >= '0' && unos[i] <= '9') {
            brojevi++;
        }
    }
    if (velika > 0 && brojevi > 0 && mala > 0 && karakteri >= 8) printf("DA");
    else printf("NE");

}
int main() {

    //zad2();
    //zad3();
    //zad4();

    return 0;
}