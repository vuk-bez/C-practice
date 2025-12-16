#include <stdio.h>
#include <stdlib.h> // dodato zbog rand funkcije
#include <time.h> // dodato da bi dobijali prave random brojeve

void ucitajMatricu(int n, int m, int matr[n][m]) {
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

void stampajMatricu(int n, int m, int matr[n][m]) {
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            printf("%2d ", matr[i][j]);
        }
        printf("\n");
    }
}

void popuniRandom(int n, int m, int matr[n][m]){
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            matr[i][j] = rand() % 10;
        }
    }
}
/*
Zbir  svih elemenata,  zbir  glavne  dijagonale,  zbir  po  kolonama  i  redovima.  
Zbir  elemenata  ispod  (iznad)  glavne (sporedne) dijagonale. 
*/
int zbirSvih(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
int zbirGlavne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i == j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
void zbirPoKolonama(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int j=0; j < m; j++){
        for(int i=0; i < n; i++){
            zbir += matr[i][j]; 
        }
        printf("%d ", zbir);
        zbir = 0;
    }
}
void zbirPoVrstama(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            zbir += matr[i][j]; 
        }
        printf("%d ", zbir);
        zbir = 0;
    }
}
int zbirIspodGlavne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i > j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
int zbirIznadGlavne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i < j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
int zbirSporedne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i == m-1-j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
int zbirIspodSporedne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i > m-1-j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
int zbirIznadSporedne(int n, int m, int matr[n][m]){
    int zbir = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(i < m-1-j)
            zbir += matr[i][j]; 
        }
    }
    return zbir;
}
/*
Kvadartolend  je  država  u  obliku  kvadrata,  podijeljena  na  NxN  manjih  kvadratića.  Kralj  zna  koliko 
vojnika patrolira u svakom dijelu kraljevstva. Sada želi saznati koliko vojnika brani granice kraljevstva. 
Pomozite  kralju  i  napišite  program  koji određuje  broj  vojnika  koji  patroliraju  granicom  kraljevstva. 
Ulaz:  Prvi  red  sadrži  broj  N  –  broj  kvadratića  po  jednoj  strani.  Sljedećih  N  redova  sadrže  po  N  cijelih 
brojeva  –  broj  vojnika  koji  patroliraju  u odgovarajućem  kvadratiću.  Izlaz:  Štampati jedan  cio  broj  –  koliko 
vojnika patrolira granicom.
*/
int kvadratolend(int n, int matr[n][n]){
    int brVojnika = 0;
    if(n == 1) {
        return matr[0][0];
    }
    
    for(int i = 0; i < n; i++) {
        brVojnika += matr[0][i];
        brVojnika += matr[n-1][i];
    }
    for(int j = 1; j < n-1; j++) {
        brVojnika += matr[j][0];
        brVojnika += matr[j][n-1];
    }

    return brVojnika;
}
/*
Za  date  koordinate  (x,  y)  polja  tabele  (matrice)  dimenazija  M  ×  N    štampati  koordinate  svih  njegovih 
susjednih  polja.  Polja  su  susjedna  kao  imaju  zajedničku  stranicu.
Ulaz: Prvi red sadrži cijele brojeve M, N, x, y (1 ≤ x ≤ M ≤ 109, 1 ≤ y ≤ N ≤ 109). Izlaz: Štampati 
koordinate susjeda, u proizvoljnom poretku, 
*/
void Susjedi(int n, int m, int matr[n][m], int x, int y) {
    if(y-1 < m)
    printf("(%d,%d)", x,y-1);
    if(y+1 < m)
    printf("(%d,%d)", x, y+1);
    if(x-1 < n)
    printf("(%d,%d)", x-1, y);
    if(x+1 < n)
    printf("(%d,%d)", x+1, y);
}
/*
Provjeriti da li je data kvadratna matrica simetrična u odnosu na glavnu dijagonalu. Ulaz: Prvi red sadrži broj 
N – dimenziju matrice (1 ≤ N ≤ 100). U sljedećih N redova unosi se po N brojeva – elementi matrice. Izlaz: 
Štampati YES ili NO,
*/
int Simetricna(int n, int matr[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(matr[i][j] != matr[j][i]){
                return 0;
            }
        }
    }
    return 1;
}
/*
Za date brojeve M i N kreirati matricu A dimenzija MxN, kao u primjeru. 
*/
void Sablon(int n, int m, int matr[n][m]){
    int br = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            for(int j = 0; j < m; j++){
                matr[i][j] = br;
                br++;
            }
        } else {
            for(int j = m-1; j >= 0; j--) {
                matr[i][j] = br;
                br++;
            }
        }
    }
}
/*
Za date brojeve M i N kreirati matricu A dimenzija MxN, kao u primjeru. 
*/
void Sablon2(int n, int m, int matr[n][m]){
    int i = 0, j = 0;
    int br = 0;
    for(int d = 0; d <= m + n - 1; d++){
        i = 0;
        j = d;
        while(i <= d && j >= 0){
            if(i < n && j < m)
            matr[i][j] = br++;
            i++;
            j--;
        }
    }
}
/*
Za  dati  prirodni  broj  N  kreirati  spiralnu  matricu  A  dimenzija  (2N+1)x(2N+1),  kao  u  primjeru.  Broj  0  se 
postavlja  u  centralno  polje  A[N][N].  Spirala  kreće  prema  gore,  a  zatim  se  vrti  suprotno  kretanju 
kazaljke sata. Ulaz: Unosi se prirodan broj N. Izlaz: Štampati traženu matricu. Za svaki broj upotrebiti po tri 
simbola.  NE RADII --- pogledati ponovo
*/

/*void Sablon3(int n, int matr[2*n+1][2*n+1]){
    int br = 0;
    int i = n, j = n;
    for(int c = 0; c < (2*n+1); c++) {
        for(int c1 = 0; c1 <= c; c1++){
            matr[i][j] = br++;
        }
        for(int c2 = 0; c2 <= c; c2++ j = (c % 2 == 0 ? -1:1) * (j + 1)){
            matr[i][j] = br++;
        }
        
    }
}*/

/*
Odrediti zbir i proizvod dvije kvadratne matrice.
*/
void zbirMatrica(int n, int m, int a[n][m], int b[n][m]){
    int c[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    stampajMatricu(n, m, c); // stampanje matrice
}
/*void mnozenjeMatrica(int n, int m, int a[n][m], int b[n][m]){
    int c[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    stampajMatricu(n, m, c); // stampanje matrice
}*/

int main() {

    srand(time(NULL));
    int n, m;
    scanf("%d%d", &n, &m);
    int matr[n][m];
    int a[n][m];
    int b[n][m];
    int matrica[2*n+1][2*n+1];

    //ucitajMatricu(n, m, matr);
    ucitajMatricu(n, m, a);
    ucitajMatricu(n, m, b);
    zbirMatrica(n, m, a, b);
    //popuniRandom(n, m, matr);
    //stampajMatricu(n, m, matr);
    //printf("\n Zbir elemenata matrice je %d. \n", zbirSvih(n,m,matr));
    //printf("Zbir elemenata na glavnoj dijagonali matrice je %d. \n", zbirGlavne(n,m,matr));
    //zbirPoKolonama(n, m, matr);
    //zbirPoVrstama(n, m, matr);
    //printf("Zbir ispod glavne dijagonale je %d. \n", zbirIspodGlavne(n,m,matr));
    //printf("Zbir iznad glavne dijagonale je %d. \n", zbirIznadGlavne(n,m,matr));
    //printf("Zbir ispod sporedne dijagonale je %d. \n", zbirIspodSporedne(n,m,matr));
    //printf("Zbir iznad sporedne dijagonale je %d. \n", zbirIznadSporedne(n,m,matr));
    //printf("Zbir elemenata na sporednoj dijagonali je %d. ", zbirSporedne(n,m,matr));
    //printf("%d", kvadratolend(n, matr));
    //Susjedi(n,m,matr, 3,3);
    /*if(Simetricna(n, matr))
    printf("Jeste simetricna");
    else
    printf("Nije simetricna");*/
    //Sablon(n, m, matr);
    //Sablon2(n, m, matr);
    //popuniNulama(n, matr);
    //Sablon3(n, matr);

    //stampajMatricu(n, m, matr);

    return 0;
}
