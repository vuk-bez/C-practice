#include <stdio.h>
#include <string.h>

/*Fajl ulaz.txt sadrži više linija teksta. Napisati C program koji iz ulaznog fajla u fajl izlaz.txt prepisuje
sve riječi koje su palindromi (čitaju se isto sa lijeva na desno i sa desna na lijevo)*/

int palindrom(char* s) {
    int indicator = 1;
    int n = strlen(s);

    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) indicator = 0;
    }

    return indicator;
}
int main() {

    FILE *fulaz = fopen("zad4_ulaz.txt" ,"r");
    FILE *fizlaz = fopen("zad4_izlaz.txt", "w");

    char linija[1000];

    while (fgets(linija, 1000, fulaz)) {
        int i = 0;
        while (linija[i] != '\n' && linija[i] != '\0') {
            int j = 0;
            char rijec[100];
            while (linija[i] != ' ' && linija[i] != '\n') {
                rijec[j++] = linija[i++];
            }
            rijec[j] = '\0';
            if (linija[i] != '\n') i++;

            if (palindrom(rijec)) fprintf(fizlaz, "%s \n", rijec);
        }
    }

    fclose(fizlaz);
    fclose(fulaz);

    return 0;
}
