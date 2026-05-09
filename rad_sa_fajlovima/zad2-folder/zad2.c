#include <stdio.h>
#include <stdlib.h>

/* U tekstualnom fajlu ulaz.txt svaka linija se sastoji od brojeva razdvojenih zarezima. Napisati C program
koji učitava broj k, a zatim kreira fajl izlaz.txt i u njega upisuje sve brojeve iz fajla ulaz.txt koji su djeljivi
brojem k.
*/

int djeljiv(int a, int k) {
    if (a % k == 0) return 1;
    else return 0;
}

int main() {
    FILE *ulaz = fopen("zad2_ulaz.txt", "r");
    FILE *izlaz = fopen("zad2_izlaz.txt", "w");

    char linija[1000] = "";

    int k;
    scanf("%d", &k);

    while (fgets(linija, 1000, ulaz)) {
        int i = 0;

        while (linija[i] != '\n') {
            int j = 0;
            char broj[100] = "";
            while (linija[i] != ',' && linija[i] != '\n') {
                broj[j++] = linija[i++];
            }
            if (linija[i] != '\n') i++;
            broj[j] = '\0';

            int x = atoi(broj);
            if (djeljiv(x, k))
                fprintf(izlaz, "%d \n", x);
        }

    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
