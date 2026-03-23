// zadaci iz fajla stringovi3.pdf

#include <stdio.h>
#include <string.h>

// ZAD 1.
// Rimske cifre zadate su karakterima 'I' (1), 'V' (5), 'X' (10), 'L' (50), 'C' (100), 'D' (500), 'M' (1000) i preko
// njih se mogu predstavljati prirodni brojevi. U rimskom zapisu, brojevi se pišu od većih cifara ka manjim,
// osim u nekoliko posebnih slučajeva:
// • I se može naći ispred V i X kako bi se dobili brojevi 4 i 9.
// • X se može naći ispred L i C kako bi se dobili brojevi 40 i 90.
// • C se može naći ispred D i M kako bi se dobili brojevi 400 i 900.
// Napisati C program koji učitava string koji predstavlja rimski broj i izračunava i štampa njegovu vrijednost u
// dekadnom brojnom sistemu.

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

// ZAD 2.
// DNK sekvenca se predstavlja kao string sastavljen od karaktera 'A', 'T', 'G' i 'C'. Za parove karaktera 'A' i
// 'T', odnosno za 'G' i 'C', kažemo da su komplementarni. Za DNK sekvencu kažemo da je
// samokomplementarna ako se njenim okretanjem sa kraja prema početku, a zatim zamjenom svakog karaktera
// njemu komplementarnim karakterom, dobija sama izvorna sekvenca. Na primjer, sekvenca "ACGT" je
// samokomplementarna, jer njeno okretanje daje "TGCA", a zatim se zamjenama 'A' -> 'T', 'T' -> 'A', 'G' -> 'C'
// i 'C' -> 'G' dobija izvorno "ACGT". Napisati C program koji učitava string koji predstavlja DNK sekvencu, a
// zatim pronalazi i štampa njenu najdužu samokomplementarnu podsekvencu (podstring).

void zad2() {

    char ulaz[100];
    scanf("%s", ulaz);

    int n = strlen(ulaz); // duzina stringa po karakterima
    for (int k = n; k >= 0; k--) {
        for (int i = 0; i < n-k+1; i++) {
            char substr[100];
            char tmp[100];
            strncpy(substr, ulaz+i, k);
            substr[k] = '\0';
            strncpy(tmp, ulaz+i, k);
            tmp[k] = '\0';

            for (int j = 0; j < k/2; j++) {
                char c = tmp[j];
                tmp[j] = tmp[k-1-j];
                tmp[k-1-j] = c;
            }
            for (int j = 0; j < k; j++) {
                if (tmp[j] == 'A') tmp[j] = 'T';
                else if (tmp[j] == 'G') tmp[j] = 'C';
                else if (tmp[j] == 'T') tmp[j] = 'A';
                else if (tmp[j] == 'C') tmp[j] = 'G';
            }

            if (strcmp(substr, tmp) == 0) {
                printf("%s\n", substr);
                return;
            }
        }
    }
}

//ZAD 4.
// Neka je data rečenica koja se sastoji isključivo od malih slova i praznina (razmaka). Napisati C program
// koji učitava takav string, a zatim u svakoj riječi iz unijete rečenice okreće redosljed samoglasnika. Riječi u
// rečenici su razdvojene prazninama.

int jeSamoglasnik(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void zad4() {
    char recenica[100];
    char izlaz[100] = ""; //inicijalizujemo prazan string
    gets(recenica); //ucitava string do prvog novog reda

    char* rijec = strtok(recenica, " ");
    while (rijec != NULL) {

        int l = 0;
        int r = strlen(rijec) - 1;
        while (l < r) {
            if (jeSamoglasnik(rijec[l]) && jeSamoglasnik(rijec[r])) {
                char c = rijec[l];
                rijec[l] = rijec[r];
                rijec[r] = c;
                l++;
                r--;
            }
            if (!jeSamoglasnik(rijec[l])) l++;
            if (!jeSamoglasnik(rijec[r])) r--;
        }

        strcat(izlaz, rijec);
        strcat(izlaz, " ");

        rijec = strtok(NULL, " ");
    }

    printf("%s\n", izlaz);

}

// ZAD 7.
// Napisati C program koji učitava string s, a zatim provjerava da li je on pangram i štampa odgovor DA ili NE.
// Pangram je svaki string koji sadrži sva slova engleskog alfabeta.
// Napomena: nije dozvoljeno praviti odvojene if naredbe za svako moguće slovo.

int zad7(char *string) {
    int i = 0;
    int slova[26] = {0};
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
    for (i = 0; i < 26; i++) {
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

   // zad2();
   // zad4();

   /* scanf(" %[^\n]", string); //cita se do novog reda
    if (zad7(string)) printf("True");
    else printf("False"); ------- za zad7 */


    return 0;
}
