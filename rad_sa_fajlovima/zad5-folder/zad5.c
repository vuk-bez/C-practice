#include <stdio.h>

/* Dat je fajl ulaz.txt koji sadrži više linija teksta. Napisati C program koji u fajl samoglasnici.txt
 * upisuje sve samoglasnike koji se pojavljuju u fajlu ulaz.txt i brojeve njihovih pojavljivanja. Analogno
 * tome, u fajl suglasnici.txt upisati svaki suglasnik i njegov broj pojavljivanja.
 */

int jeSamoglasnik(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int main () {

    FILE *fulaz = fopen("zad5_ulaz.txt", "r");
    FILE *fsamoglasnici = fopen("samoglasnici.txt", "w");
    FILE *fsuglasnici = fopen("suglasnici.txt", "w");

    char linija[1000] = "";
    int pojavljivanja[26] = {0};
    while (fgets(linija, 1000, fulaz)) {
        int i = 0;
        while (linija[i] != '\n' && linija[i] != '\0') {
            if (linija[i] != ' ') {
                pojavljivanja[linija[i] - 'a'] ++;
            }
            i++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (jeSamoglasnik(i+'a') && pojavljivanja[i] != 0) fprintf(fsamoglasnici, "%c %d\n", i+'a', pojavljivanja[i]);
        else if (!jeSamoglasnik(i + 'a') && pojavljivanja[i] != 0)fprintf(fsuglasnici, "%c %d\n", i+'a', pojavljivanja[i]);
    }

    fclose(fsamoglasnici);
    fclose(fsuglasnici);
    fclose(fulaz);

    return 0;
}