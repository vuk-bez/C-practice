#include <stdio.h>
#include <string.h>

/* Tekstualni fajl ulaz.txt sadrži više linija teksta. Napisati C program koji učitava string w sastavljen od
malih slova engleskog alfabeta, a zatim kreira fajl izlaz.txt i u njega prepisuje sve riječi iz fajla ulaz.txt koje
kao podstring sadrže w. */

int podstring(char* string, char* w) {

    for (int i = 0; string[i] != '\0' && i < strlen(string) - strlen(w) - 1; i++) {
        char temp[100] = "";
        int k = 0;
        for (int j = i; j < strlen(w) + i - 1; j++) {
            temp[k] = string[j];
            k++;
        }
        temp[strlen(temp)] = '\n';
        if (strcmp(temp, w) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {

    FILE *fulaz;
    fulaz = fopen ("zad1_ulaz.txt", "r"); //cita podatke iz fajla

    FILE *fizlaz;
    fizlaz = fopen ("izlaz.txt", "w");

    char w[100] = "";
    fgets (w, 100, stdin);

    char ulaz[1000] = "";
    while (fgets(ulaz, 1000, fulaz)) {
        int i = 0;

        while (ulaz[i] != '\n') {
            char posmatrana[1000] = "";
            int j = 0;
               while (ulaz[i] != ' ' && ulaz[i] != '\n') {
                   posmatrana[j] = ulaz[i];
                   j++;
                   i++;
               }
            posmatrana[i] = '\0';

            if (podstring(posmatrana, w)) {
                fprintf(fizlaz, "%s \n", posmatrana);
            }
            if (ulaz[i] != '\n') {
                i++;
            }
        }

        i++;
    }

    fclose(fulaz);
    fclose(fizlaz);

    return 0;
}