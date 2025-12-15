#include <stdio.h>

void ucitajNiz(int n, int niz[]) {
    for(int i=0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
}

void stampajNiz(int n, int niz[]) {
    for(int i=0; i < n; i++) {
        printf("%d", niz[i]);
    }
}
/*
Napisati metod void uslov(int[] x) koji štampa sve elemente niza x koji su po 
apsolutnoj vrijednosti prosti brojevi ili su oblika ±2k, za neki prirodan broj k.
*/
int jeProst(int n) {
    if(n == 1) {
        return 0;
    }
    for(int i = 2; i <= n/2; i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}
int oblik2naK(int n) {
    int ind = 2;
    while(ind <= n) {
        if(ind == n){
            return 1;
        }
        ind *= 2;
    }
    return 0;
}
void uslov(int n, int niz[]){
    
    for(int i = 0; i < n; i++) {
        if(niz[i] < 0) {
            niz[i] *= -1;
        }
        if(jeProst(niz[i]) || oblik2naK(niz[i])) {
            printf("%d ", niz[i]);
        }
    }
}
/*
Napisati metod void jedinice(int[] b, int k, int n) koji štampa sve elemente 
niza b koji u zapisu u sistemu sa osnovom k imaju bar n jedinica.
*/
int brojJedinica(int n, int k) {
    int brJedinica = 0;
    while(n > 0) {
        if(n % k == 1) {
            brJedinica++;
        }
        n /= k;
    }
    return brJedinica;
}

void jedinice(int n, int niz[], int k, int x){
    for(int i = 0; i < n; i++) {
        if(brojJedinica(niz[i], k) >= x){
            printf("%d ", niz[i]);
        }
    }
}
/*
Napisati metod int parneCifre(int[] b, int k) koji štampa sve elemente niza b 
koji u dekadnom zapisu imaju bar k parnih brojeva. Metod vraća broj takvih elemenata u nizu. 
*/
int parneCifreJedan(int n, int k) {
    int brParnihCifara = 0;
    int cifra;
    while(n > 0) {
        cifra = n%10;
        if(cifra%2==0){
            brParnihCifara ++;
        }
        n /= 10;
    }
    if(brParnihCifara >= k){
        return 1;
    }
    return 0;
}
int parneCifre(int n, int niz[], int k) {
    int brojac = 0;
    
    for(int i = 0; i < n; i++) {
        if(parneCifreJedan(niz[i], k)) {
            brojac++;
        }
    }
    return brojac;
}
/*
Napisati metod void prosteCifre(int[] b) koji štampa sve elemente niza b koji u 
dekadnom zapisu imaju bar jedan prost broj. 
*/
int jeProstaCifra(int n) {
    int cifra;
    while(n > 0) {
        cifra = n%10;
        if(jeProst(cifra)){  // koristimo vec napravljenu funkciju od prije
            return 1;
        }
        n /= 10;
    }
    return 0;
}

void prosteCifre(int n, int niz[]){
    for(int i = 0; i < n; i++) {
        if(jeProstaCifra(niz[i])){
            printf("%d ", niz[i]);
        }
    }
}
/*
Napisati metod int minArray(int [] b) koji vraća onaj element niza koji je najbliži 
aritmetičkoj sredini niza b. Ako ima više takvih elemenata, vratiti bilo koji. 
*/
float AritmSredina(int n, int niz[]){
    int zbir = 0;
    for(int i = 0; i < n; i++){
        zbir += niz[i];
    }
    return (float)zbir/n;
}

int minArray(int n, int niz[]){
    float minRazlika;
    float trenutnaRazlika;
    int minIndeks = 0;
    float sredina = AritmSredina(n, niz);

    minRazlika = sredina - niz[0];
    if (minRazlika<0){
        minRazlika *= -1;
    }
    
    for(int i = 0; i < n; i++){
        trenutnaRazlika = sredina - niz[i];
        if (trenutnaRazlika < 0){
            trenutnaRazlika *= -1;
        }
        if (trenutnaRazlika < minRazlika){
            minRazlika = trenutnaRazlika;
            minIndeks = i;
        }
        
    }
    return niz[minIndeks];
}

/*
Napisati metod int[] noviNiz(int [] b) koji vraća novi niz takav da se i-ti element 
tog niza dobija kao najveća cifra u dekadnom zapisu i-tog elementa niza b.
*/
int najvecaCifra(int n) {
    int cifra;
    int najvecaCifra = 0;
    while (n > 0) {
        cifra = n % 10;
        if(cifra > najvecaCifra) {
            najvecaCifra = cifra;
        }
        n /= 10;
    }
    return najvecaCifra;
}
void noviNiz(int n, int niz[]){
    for(int i = 0; i < n; i++) {
        printf("%d ", najvecaCifra(niz[i]));
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int niz[n];
    ucitajNiz(n, niz);
    //uslov(n, niz);
    //jedinice(n, niz, 2, 3);
    //printf("%d", parneCifre(n, niz, 2));
    //prosteCifre(n, niz);
    //printf("%d", minArray(n, niz));
    noviNiz(n, niz);

    
    return 0;
}