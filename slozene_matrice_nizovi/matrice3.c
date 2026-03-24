#include <stdio.h>

void unosMatrix(int m, int n, int matrix[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void stampaMatrix(int m, int n, int matrix[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ZAD 1.
// Maksimalno uzorkovanje iz matrice brojeva definiše se na sljedeći način. Za neki broj k, matrica
// se dijeli u disjunktne podmatrice formata k×k. Iz svake podmatrice se uzima element sa
// maksimalnom vrijednošću i takvi maksimumi formiraju novu matricu, k puta manjih dimenzija od
// ulazne. Napisati program koji za date brojeve m, n i k, i ulaznu matricu formata m×n, pronalazi i
// štampa matricu koja predstavlja rezultat maksimalnog uzorkovanja. Pretpostaviti da će brojevi m i n
// uvijek biti djeljivi brojem k.
int najveciBroj(int m, int n, int k, int pocI, int pocJ, int matrix[m][n]) {
    
    int maxBr = 0;
    
    for(int i = pocI; i < pocI+k; i++) {
        for(int j = pocJ; j < pocJ+k; j++) {
            if(matrix[i][j] > maxBr){
                maxBr = matrix[i][j];
            }
        }
    }

    return maxBr;
}

void zad1(int m, int n, int k, int matrix[m][n], int rez[m/k][n/k]) {
    
    int vrste = m/k;
    int kolone = n/k;
    
    for(int i = 0; i < vrste; i++) {
        for(int j = 0; j < kolone; j++){
            rez[i][j] = najveciBroj(m, n, k, i*k, j*k, matrix);
        }
    }
}

// ZAD 2.
// U igri sudoku polazi se od matrice formata n2×n2 , za neki prirodan broj n. Neka polja u
// matrici sadrže brojeve iz skupa {1,2 , ..., n2 } i ona su popunjena, dok za polja koja sadrže nulu
// kažemo da su prazna. Cilj igre je popuniti sva prazna polja brojevima iz skupa {1,2 , ..., n2 } , i to
// tako da budu zadovoljena sljedeća ograničenja. Ni u jednoj vrsti se ne smije ponoviti isti broj više
// od jednog puta, a isto važi i za kolone. Takođe, matrica je podijeljena na n2 ćelija formata n×n, i u
// ćelijama takođe nijesu dozvoljena ponavljanja istog broja. Napisati program koji učitava broj n,
// zatim matricu formata n2×n2 i na kraju brojeve x i y - vrstu i kolonu jednog od praznih polja u
// matrici. Izlaz programa treba da bude niz brojeva koje je moguće upisati na poziciju (x, y) a da pri
// tome ne bude narušeno nijedno od navedenih ograničenja.

void zad2(int n, int matrix[n*n][n*n], int x, int y) {
    int broj = 1;
    for(int broj = 1; broj <= n*n; broj++){
        int pojavljivanje = 1;
        for(int i = 0; i < n*n; i++) {
            if(matrix[x][i] == broj || matrix[i][y] == broj){
                pojavljivanje = 0;
                break;
            }
        }
        if(!pojavljivanje) {
            continue;
        }
        for(int i = x/n; i < n; i++) {
            for(int j = y/n; j < n; j++) {
                if(matrix[i][j] == broj){
                    pojavljivanje = 0;
                    break;
                }
            }
        }
        if(pojavljivanje) {
            printf("%d ", broj);
        }
    }
    
}

// ZAD 3.
// Napisati program koji učitava binarnu matricu (koja se sastoji isključivo od nula i jedinica)
// formata m×n, a zatim pronalazi i štampa površinu najvećeg pravougaonika u njoj. Ivicu
// pravougaonika čine jedinice, a u njegovoj unutrašnjosti se može nalaziti bilo šta. Površina
// pravougaonika se računa kao broj elemenata matrice koje on obuhvata, uključujući i njegovu ivicu.
// Među pravougaonicima mogu postojati preklapanja.

int povrsinaPravougaonika(int pocI, int pocJ, int krajI, int krajJ){    
    return (pocI-krajI+1)*(pocJ-krajJ+1);
}

void zad3(int n, int m, int matrix[m][n]) {

    int pocI = 0;
    int pocJ = 0;
    int krajJ = 0;
    int krajI = 0;
    int maxP = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1) {
                pocI = i;
                pocJ = j;
                while(j < n && matrix[pocI][j] == 1) {
                    krajJ = j;
                    j++;
                }
                while(i < m && matrix[i][pocJ] == 1){
                    krajI = i;
                    i++;
                }
                i = pocI;
                j = pocJ;
                while(j < n && matrix[krajI][j+1] == 1){
                    if(krajJ <= j) {
                        break;
                    } 
                    j++;
                }
                krajJ = j;
                i = pocI;
                j = pocJ;
                while(i < m && matrix[i+1][krajJ] == 1) {
                    if(krajI <= i){
                        break;
                    }
                    i++;
                }
                krajI = i;
                if(povrsinaPravougaonika(pocI,pocJ,krajI,krajJ) > maxP){
                    maxP = povrsinaPravougaonika(pocI,pocJ,krajI,krajJ);
                }
                i = pocI;
                j = pocJ;
            }
        }
    }

    printf("%d", maxP);
}

int main() {
    
/*  int m, n, k;
    scanf("%d%d%d", &m, &n, &k);

    int matrix[m][n];
    int rez[m/k][n/k];

    unosMatrix(m, n, matrix);
    zad1( m, n, k, matrix, rez);

    stampaMatrix(m/k, n/k, rez);  --- uz zadatak 1 */

/*  int n;
    scanf("%d", &n);
    int matrix[n*n][n*n];
    unosMatrix(n*n,n*n, matrix);
    
    int x, y;
    scanf("%d%d", &x, &y);

    zad2(n, matrix, x, y); --- uz zadatak 2 */

    int m,n;
    scanf("%d%d", &m, &n);
    int matrix[m][n];
    
    unosMatrix(m,n,matrix);
    zad3(n,m,matrix);



    return 0;
}