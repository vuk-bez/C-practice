#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ZAD 1. Napisati program koji provjerava da li je email adresa validna.
// Email adresa je validna ako je formata personal_info@domain. 
// Personal_info mora biti duzi od 3 karaktera, sadrzati samo brojeve, slova i ".-_"
// Domain mora biti duzi od 3 karaktera, samo slova i mora imati bar jednu ".", ne smije pocinjati njome

void zad1(char* adresa) {
    int prijeAt = 0;
    int posleAt = 0;
    int AtPosition = 0;
    int indicatorAt = 0;
    int tacka = 0;

    for(int i = 0; adresa[i] != '\0'; i++) {
        
        if(adresa[i] == '@') {
            indicatorAt ++;
            AtPosition = i;
            continue;
        }
        if(AtPosition != 0 && adresa[AtPosition + 1] == '.') {
            printf("Nije validna!");
            return;
        } 
        if(((adresa[i] >= 'A' && adresa[i] <= 'Z') || (adresa[i] >= 'a' && adresa[i] <= 'z') || adresa[i] == '.' || adresa[i] == '-' || adresa[i] == '_') && !indicatorAt) {
            prijeAt++;
        } else if (((adresa[i] >= 'A' && adresa[i] <= 'Z') || (adresa[i] >= 'a' && adresa[i] <= 'z') || adresa[i] == '.') && indicatorAt) {
            posleAt++;
            if(adresa[i] == '.') tacka++;
        } else {
            printf("Nije validna!");
            return;
        }
        
    }

    if(posleAt > 3 && prijeAt > 3 && tacka > 0) printf("Adresa je validna!");
    else printf("Nije validna!");
    
}

// ZAD 2.
// Dozvoljena je sljedeća operacija: u rijeci uzmemo prvi suglasnik i zamijenimo mjesta sa posljednjim suglasnikom;
// drugi suglasnik zamijeni mjesta sa pretposljednjim suglasnikom itd. 
// Ako poslije te operacije opet dobijemo polaznu riječ, tada takvu nazivamo bezglasni palindrom 
// (npr. takve su riječi: sos, rare, rotor, gong, karaoke). 
// Napisati program koji provjerava da li je data riječ bezglasni palindrom.

// pomocna funkcija koja provjerava da li je samoglasnik
int JeSamoglasnik(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

void zad2(char* string) {
    
    char polazniCpy[100];
    strcpy(polazniCpy, string);

    int l = strlen(string) - 1;
    int r = 0;

    while(r < l) {
        if(!JeSamoglasnik(string[r]) && !JeSamoglasnik(string[l])) {
            char temp = string[r];
            string[r] = string[l];
            string[l] = temp;
            r++; l--;
        } else {
            if(JeSamoglasnik(string[r])) r++;
            if (JeSamoglasnik(string[l])) l--;
        }
    }

    if(strcmp(polazniCpy, string) == 0) printf("Jeste bezglasni palindrom");
    else printf("Nije bezglasni palindrom");
}

// ZAD 3.
// Provjeriti da li su stringovi izomorfni. Unose se dva stringa.
void izomorfni_stringovi() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    char mapiranje[26] = {0};

    if (strlen(s1) != strlen(s2)) {
        printf("NE\n");
        return;
    }

    int i;
    for (i = 0; s1[i] != '\0'; i++) {
        char idx = s1[i] - 'a';
        char c = s2[i];
        if (mapiranje[idx] == 0)
            mapiranje[idx] = c;
        else if (mapiranje[idx] != c) {
            printf("NE\n");
            return;
        }
    }

    int j;
    for (i = 0; i < 25; i++) {
        for (j = i+1; j < 26; j++) {
            if (mapiranje[i] == mapiranje[j] && mapiranje[i] != 0) {
                printf("NE\n");
                return;
            }
        }
    }

    printf("DA\n");
}

int main() {
    
    //char* adresa = (char*)malloc(100*sizeof(char));
    //scanf("%s", adresa);
    //zad1(adresa);
    //zad2(adresa);
    izomorfni_stringovi();

    return 0;
}