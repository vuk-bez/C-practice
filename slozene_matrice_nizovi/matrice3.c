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

// zadatak jedan sa fajla matrice3
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

// zadatak dva sa fajla matrice3
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

// zadatak tri sa fajla matrice3
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