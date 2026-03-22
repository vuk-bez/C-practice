// zadaci iz fajla stringovi3.pdf

#include <stdio.h>
#include <string.h>

/*
* Rimske cifre zadate su karakterima 'I' (1), 'V' (5), 'X' (10), 'L' (50), 'C' (100), 'D' (500), 'M' (1000) i preko
njih se mogu predstavljati prirodni brojevi. U rimskom zapisu, brojevi se pišu od većih cifara ka manjim,
osim u nekoliko posebnih slučajeva:
• I se može naći ispred V i X kako bi se dobili brojevi 4 i 9.
• X se može naći ispred L i C kako bi se dobili brojevi 40 i 90.
• C se može naći ispred D i M kako bi se dobili brojevi 400 i 900.
Napisati C program koji učitava string koji predstavlja rimski broj i izračunava i štampa njegovu vrijednost u
dekadnom brojnom sistemu. */

int zad1(char *string) {
    int i = 0;
    int num = 0;

    while (string[i] != '\0') {
        if (string[i] == 'I' && string[i + 1] == 'V') {
            num += 4;
            i += 2;
            continue;
        } else if (string[i] == 'I' && string[i + 1] == 'X') {
            num += 9;
            i += 2;
            continue;
        } else if (string[i] == 'X' && string[i + 1] == 'L') {
            num += 40;
            i += 2;
            continue;
        } else if (string[i] == 'X' && string[i + 1] == 'C') {
            num += 90;
            i += 2;
            continue;
        } else if (string[i] == 'C' && string[i + 1] == 'D') {
            num += 400;
            i += 2;
            continue;
        } else if (string[i] == 'C' && string[i + 1] == 'M') {
            num += 900;
            i += 2;
            continue;
        }

        // obične cifre
        if (string[i] == 'I') num += 1;
        else if (string[i] == 'V') num += 5;
        else if (string[i] == 'X') num += 10;
        else if (string[i] == 'L') num += 50;
        else if (string[i] == 'C') num += 100;
        else if (string[i] == 'D') num += 500;
        else if (string[i] == 'M') num += 1000;

        i++;
    }

    return num;
}

/*
 *Napisati C program koji učitava string s, a zatim provjerava da li je on pangram i štampa odgovor DA ili NE.
 *Pangram je svaki string koji sadrži sva slova engleskog alfabeta.
 *Napomena: nije dozvoljeno praviti odvojene if naredbe za svako moguće slovo. */

int zad7(char *string) {
    int i = 0;
    int slova[25];
    while (string[i] != '\0') {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += 32;
        }
        i++;
    }
    i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'a' && string[i] <= 'z') {
            slova[string[i]-97] ++;
        }
        i++;
    }
    for (i = 0; i < 25; i++) {
        if (slova[i] == 0) {
            return 0;
        }
    }
    return 1;


}

int main() {
    char string[100];

   /* printf("Unesi rimski broj: ");
    scanf("%s", string);
    printf("%d\n", zad1(string));  ----- za zad1 */

    scanf(" %[^\n]", string); //cita se do novog reda
    if (zad7(string)) printf("True");
    else printf("False");


    return 0;
}
