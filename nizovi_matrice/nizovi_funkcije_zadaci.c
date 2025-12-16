#include <stdio.h>
#include <stdlib.h> // dodato zbog zadataka sa random funkcijom
#include <time.h> // dodato zbog zadataka za random generator brojeva
#include <math.h> // dodato zbog korijena


// ZADACI IZ FAJLA Java_2013_Nizovi.pdf pocev od 11.
void ucitajNiz(int n, int niz[]) {
    for(int i=0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
}
void ucitajNizDouble(int n, double niz[]) { //za zadatke iz analiticke
    for(int i=0; i < n; i++) {
        scanf("%lf", &niz[i]);
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
/*
Napisati metod double[] noviNiz(int [] b) koji vraća novi niz takav da se i-ti 
element tog niza dobija kao apsolutna vrjednost razlike i-tog elementa niza b i aritmetičke 
sredine niza b.  
*/
void noviRazlikaNiz(int n, int niz[]){
    float sredina = AritmSredina(n, niz); //funkcija je vec prije napisana
    for(int i = 0; i < n; i++) {
        if(niz[i]-sredina < 0)
        printf("%f ", (niz[i] - sredina)*-1);
        else
        printf("%f ", niz[i] - sredina);
    }
}
/*
Napisati metod double[] najnovijiNiz(int [] b, double eps) koji vraća novi 
niz koji sadrži sve elemente niza b koji su na rastojanju ne većem od eps od aritmetičke 
sredine niza b. 
*/
void najnovijiNiz(int n, int niz[], float eps) {
    float sredina = AritmSredina(n, niz); //funkcija koju smo prije pisali
    float razlika;
    for(int i = 0; i < n; i++) {
        razlika = niz[i] - sredina;
        if(razlika < 0)
        razlika *= -1;
        if(razlika < eps)
        printf("%d ", niz[i]);
    }
}
/*
Napisati metod void  frekvencije(int[] b) koji za svaki element niza b štampa 
koliko se puta taj element pojavljuje u nizu b.  Smatrati da svi elementi niza b pripadaju 
intervalu [1,100].
*/
void frekvencije(int n, int niz[]) {
    int brojac[101] = {0};
    for(int i = 0; i < n; i++) {
        brojac[niz[i]] ++;
    }
    for(int i = 0; i < 101; i++){
        if(brojac[i] != 0) {
            printf("Broj %d se pojavljuje %d puta. \n", i, brojac[i]);
        }
    }
}
/*
Napisati metod void  kockica(int n) koji simulira bacanje kockice za jamb n puta i 
štampa koliko se puta svaki broj pojavljuje u tih n bacanja. Napomena: koristiti klasu Random 
i generisati slučajan cio broj iz intervala [1,6].
*/
int baciKocku() { 
    return (rand() % 6) + 1; //baca jednom kockicu
}
void kockica(int n){
    int niz[7] = {0};
    for(int i = 0; i < n; i++){
        niz[baciKocku()] ++;
    }
    for(int i = 1; i < 7; i++){
        printf("Broj %d je bacen %d puta. \n", i, niz[i]);
    }
}
/*
Napisati metod void  ocjene(int[] b) koji na osnovu broja bodova studenata na ispitu 
upisanih u niz b štampa koliko ima ocjena A, B, C, D, E i F. Ocjena A se dobija za osvojenih 
bar 90 bodova, ocjena B za bar 80 bodova, C za bar 70 bodova, D za bar 60, E za bar 50 bodova 
a F za manje od 50 bodova. 
*/
void ocjene(int n, int niz[]){
    int ocjene[6] = {0};
    for(int i = 0; i < n; i++) {
        if(niz[i] < 50)
            ocjene[0]++;
        else if(niz[i] < 60 && niz[i] >= 51)
            ocjene[1]++;
        else if(niz[i] < 70 && niz[i] >= 61)
            ocjene[2]++;
        else if(niz[i] < 80 && niz[i] >= 71)
            ocjene[3]++;
        else if(niz[i] < 90 && niz[i] >= 81)
            ocjene[4]++;
        else
            ocjene[5]++;
    }
    for(int i = 0; i < 6; i++){
        printf("Broj ocjena %d je %d. \n", i+5, ocjene[i]);
    }
}
/*
Napisati metod void  histogram(int[] b) koji na osnovu broja bodova studenata na 
ispitu upisanih u niz b štampa koliko ima ocjena A, B, C, D, E i F. Iza ocjene treba štampati 
onoliko zvjezdica koliko ima studenata koji su dobili tu ocjenu (vidi sliku). Ocjena A se dobija 
za osvojenih bar 90 bodova, ocjena B za bar 80 bodova, C za bar 70 bodova, D za bar 60, E za 
bar 50 bodova a F za manje od 50 bodova.  
A – 5 ***** 
B – 1 * 
C – 3 *** 
D – 0  
E – 4 **** 
F – 7 *******
*/
void histogram(int n, int niz[]){
    int ocjene[6] = {0};
    for(int i = 0; i < n; i++) {
        if(niz[i] < 50)
            ocjene[0]++;
        else if(niz[i] < 60 && niz[i] >= 51)
            ocjene[1]++;
        else if(niz[i] < 70 && niz[i] >= 61)
            ocjene[2]++;
        else if(niz[i] < 80 && niz[i] >= 71)
            ocjene[3]++;
        else if(niz[i] < 90 && niz[i] >= 81)
            ocjene[4]++;
        else
            ocjene[5]++;
    }
    
    printf("A - %d ", ocjene[5]);
    for(int i = 1; i <= ocjene[5]; i++){
        printf("*");
    }
    printf("\n");
    printf("B - %d ", ocjene[4]);
    for(int i = 1; i <= ocjene[4]; i++){
        printf("*");
    }
    printf("\n");
    printf("C - %d ", ocjene[3]);
    for(int i = 1; i <= ocjene[3]; i++){
        printf("*");
    }
    printf("\n");
    printf("D - %d " , ocjene[2]);
    for(int i = 1; i <= ocjene[2]; i++){
        printf("*");
    }
    printf("\n");
    printf("E - %d ", ocjene[1]);
    for(int i = 1; i <= ocjene[1]; i++){
        printf("*");
    }
    printf("\n");
    printf("F - %d ", ocjene[0]);
    for(int i = 1; i <= ocjene[0]; i++){
        printf("*");
    }
    printf("\n");
}
/*
Napisati metod int krugovi(double[] x, double[] y, double a, double 
b, double r) koji štampa sve parove brojeva (x[i], y[i]), po jedan par u redu, takve 
da tačka sa koordinatama (x[i], y[i]) pripada krugu čiji je centar tačka (a,b) i 
poluprečnik r. Metod vraća broj takvih parova. 
*/
int krugovi(int n, double x[], double y[], double a, double b, double r){
    int brojac = 0;
    for(int i = 0; i < n; i++) {
        double rastojanje = sqrt((x[i]-a)*(x[i]-a) + (y[i]-b)*(y[i]-b));
        if (rastojanje <= r)
        brojac++;
    }
    return brojac;
}
/*
Skup pravougaonika sa stranicama paralelnim koordinatnim osama opisuje se preko 4 niza 
cijelih brojeva a,b,c,d, tako da tačke (a[i],b[i]) i (c[i],d[i]) predstavljaju 
dijagonalne tačke i-tog pravougaonika. Napisati metod int 
najveciPravougaonik(int[] a, int[] b, int[] c, int[] d) koji vraća 
indeks pravougaonika najveće površine.
*/
int najveciPravougaonik(int n, int a[], int b[], int c[], int d[]){
    int maxarea = 0;
    int maxind = 0;
    for(int i = 0; i < n; i++) {
        int h = a[i] - c[i];
        int w = b[i] - d[i];
        if(h<0)
            h *= -1;
        if(w<0)
            w *= -1;
        int area = h*w;
        if(area>maxarea){
            maxarea = area;
            maxind = i;
        }
    }
    return maxind;
}
/*
Napisati metod int krugovi(double[] x, double[] y) koji štampa sve parove 
brojeva (x[i], y[i]), po jedan par u redu, takve da tačka sa koordinatama (x[i], 
y[i]) pripada osjenčenom dijelu ravni sa slike. Centar oba kruga je u tački (0,0), poluprečnici 
su im redom 4 i 6, dok je prava  data jednačinom x-y-4=0. ---POGLEDATI FAJL ZA SLIKU
*/
void krugoviDva(int n, double x[], double y[]){
    for(int i = 0; i < n; i++) {
        float rastojanje = sqrt(x[i]*x[i] + y[i]*y[i]);
        if(x[i] >= 0 && y[i] >= 0 && rastojanje <= 4)
            printf("(%lf,%lf)", x[i], y[i]);
        else if(x[i] >= 0 && y[i] >= 0 && rastojanje <= 6 && y[i]<=x[i]-4)
            printf("(%lf,%lf)", x[i], y[i]);
        else if(x[i] >= 0 && y[i] <= 0 && rastojanje <= 4 && y[i]<=x[i]-4)
            printf("(%lf,%lf)", x[i], y[i]);
        else if(x[i] <= 0 && y[i] <= 0 && rastojanje >= 4 && rastojanje <= 6 && y[i]>=x[i]-4)
            printf("(%lf,%lf)", x[i], y[i]);     
    }
}
/*
Polinom jedne promjenljive P(x) = a0 + a1x + a2xx + a3xxx +.... anx(n puta) zadaje se nizom svojih koeficijenata. 
Napisati metod double valueOfPoly(double[] a, double x) koji izračunava 
vrijednost polinoma P u tački x, ako je P zadat nizom koefecijanata a.
*/
double valueofPoly(int n, double a[], double x) {
    double zbir = 0;
    double cinilac = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++){
            cinilac *= x;
        }
        zbir += a[i]*cinilac;
        cinilac = 1;
    }
    return zbir;
}
/*Polinom jedne promjenljive P(x) = a0 + a1x + a2xx + a3xxx +.... anx(n puta)  zadaje se nizom svojih koeficijenata. 
Napisati metod double hornerValue(double[] a, double x) koji primjenom 
Hornerove šeme izračunava vrijednost polinoma P u tački x, ako je P zadat nizom koefecijanata 
a. Napomena: opis Hornerove šeme: http://math.fullerton.edu/mathews/n2003/HornerMod.html 
*/

double hornerValue(int n, double a[], double x) {
    double cinilac = a[n-1]*x + a[n-2];
    for(int i = n-3; i >= 0; i--) {
        cinilac = x*cinilac + a[i];
    }
    return cinilac;
}
/*
Napisati metod double[] addPoly(double[] a, double[] b) koji izračunava i 
vraća koeficijente polinoma  R(x) = P(x) + Q(x)
*/

void addPoly(int n, double a[], double b[]){
    for(int i = 0; i < n; i++){
        printf("%lf ", a[i]+b[i]);
    }
}
/*
Napisati metod double[] derivPoly(double[] a) koji izračunava i 
vraća koeficijente polinoma P(x) - izvod od A(x)
*/
double derivPoly(int n, double a[]){
    for(int i = 0; i < n; i++) {
        printf("%.1lf ", a[i]*i);
    }
}
/*
Napisati metod double[] multPoly(double[] a, double[] b) koji izračunava i 
vraća koeficijente polinoma P(t) * Q(t)
*/
void multPoly(int n, double a[], double b[]) {
    int duzina = 2*n - 1;
    double c[duzina];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            double cinilac = a[i]*b[j];
            c[i+j] += cinilac;
        }
    }
    for(int i = 0; i < duzina; i++){
        printf("%lf ", c[i]);
    }

}
int main() {
    
    srand(time(NULL)); // dodato da bi rand funkcija svaki put generisala random brojeve
    
    int n;
    scanf("%d", &n);
    int niz[n];
    double x[n];
    double y[n];
    int a[n];
    int b[n];
    int c[n];
    int d[n];
    //ucitajNiz(n, a);
    //ucitajNiz(n, b);
    //ucitajNiz(n, c);
    //ucitajNiz(n, d);
    ucitajNizDouble(n, x);
    //ucitajNizDouble(n, y);
    //ucitajNiz(n, niz);
    //uslov(n, niz);
    //jedinice(n, niz, 2, 3);
    //printf("%d", parneCifre(n, niz, 2));
    //prosteCifre(n, niz);
    //printf("%d", minArray(n, niz));
    //noviNiz(n, niz);
    //noviRazlikaNiz(n, niz);
    //najnovijiNiz(n, niz, 5);
    //frekvencije(n, niz);
    //kockica(n);
    //ocjene(n, niz);
    //histogram(n,niz);
    //printf("%d ", krugovi(n, x, y, 0, 0, 10));
    //printf("%d", najveciPravougaonik(n, a, b, c, d));
    //krugoviDva(n, x, y);
    printf("%lf", valueofPoly(n, x, 3));
    printf("%lf", hornerValue(n, x, 3));
    //addPoly(n, x, y);
    //derivPoly(n, x);
    //multPoly(n, x, y);

    
    return 0;
}