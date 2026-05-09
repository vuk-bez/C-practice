#include <stdio.h>

/*Fajl ulaz.txt sadrži više linija teksta. Napisati C program koji iz ulaznog fajla u fajl izlaz.txt prepisuje
sve alternirajuće riječi. Za riječ kažemo da je alternirajuća ako se u njoj naizmjenično smjenjuju suglasnici i
samoglasnici.*/

int jeSamoglasnik(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int alternirajuca (char* string) {
    int indicator = 1;
    for (int i = 1; string[i] != '\0'; i++) {
        if (jeSamoglasnik(string[i]) == jeSamoglasnik(string[i-1])) indicator = 0;
    }
    return indicator;
}

int main() {

    FILE *fulaz = fopen("zad3_ulaz.txt" , "r");
    FILE *fizlaz = fopen("zad3_izlaz.txt", "w");
    char linija [1000] = "";
    while (fgets(linija, 1000, fulaz)) {
        int i = 0;
        while (linija[i] != '\n') {
            char rijec[100] = "";
            int j = 0;
            while (linija[i] != ' ' && linija[i] != '\n') {
                rijec[j++] = linija[i++];
            }
            if (linija[i] != '\n') i++;

            if (alternirajuca(rijec)) fprintf(fizlaz, "%s \n", rijec);
        }
    }

    fclose(fizlaz);
    fclose(fulaz);

    return 0;
}