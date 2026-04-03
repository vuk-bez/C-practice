// Zadaci iz fajla matrice_dodatni_zadaci
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ucitajMatricu(int matr[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}

void stampajMatricu(int matr[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

// ZAD 1.
//Дата jе шаховска табла на коjоj jе распоређено осам дама. Напиши програм коjи проверава да
//lи се неке две даме нападаjу (две даме се нападаjу ако се налазе у истоj врсти, истоj колони или на истоj
//диjагонали).

void zad1(int matr[][100], int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == 1) {
                //provjeravam red i kolonu
                for (int k = 0; k < m; k++) {
                    if (matr[i][k] == 1 && k != j) {
                        printf("Napadaju se");
                        return;
                    }
                    if (matr[k][j] == 1 && k != i) {
                        printf("Napadaju se");
                        return;
                    }
                }
                //provjeravam dijagonale (prvo direktne, pa suprotne)
                for (int k = -m; k < m; k++) {
                    int vrsta = i + k;
                    int kolona = j + k;
                    if (vrsta >= 0 && kolona >= 0 && kolona < m && vrsta < n) {
                        if (vrsta != i && kolona != j && matr[vrsta][kolona] == 1) {
                            printf("Napadaju se");
                            return;
                        }
                    }
                }
                for (int k = -m; k < m; k++) {
                    int vrsta = i + k;
                    int kolona = j - k;
                    if (vrsta >= 0 && kolona >= 0 && kolona < m && vrsta < n) {
                        if (vrsta != i && kolona != j && matr[vrsta][kolona] == 1) {
                            printf("Napadaju se");
                            return;
                        }
                    }
                }
            }
        }
    }

    printf("Ne napadaju se");
}

// ZAD 2.
// У игрици Minesweeper на пољима се налазе сакривене бомбе и задатак играча jе да их пронађе.
// Играчу се приказуjе табла са броjевима где сваки броj представља броj бомби коjе се налазе у околини датог
// поља (гледаjу се околна поља у свих 8 смерова). Твоj задатак jе да започнеш програмирање ове игре тако
// што ћеш написати програм коjи за дати распоред бомби одређуjе ове броjеве.

void zad2(int matr[][100], int m, int n) {
    int rez[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rez[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matr[i][j] == 1) {
                if (i+1 < m) rez[i+1][j]++;
                if (j+1 < n) rez[i][j+1]++;
                if (i+1 < m && j+1 < n) rez[i+1][j+1]++;
                if (i-1 >= 0) rez[i-1][j]++;
                if (j-1 >= 0) rez[i][j-1]++;
                if (i-1 >= 0 && j-1 >= 0) rez[i-1][j-1]++;
                if (i-1 >= 0 && j+1 < n) rez[i-1][j+1]++;
                if (i+1 < m && j-1 >= 0) rez[i+1][j-1]++;
            }
        }
    }

    stampajMatricu(rez, m, n);
}
// ZAD 3.
// На папиру подељеном на n × n jединичних квадратића, нацртано jе неколико правоугаоника
// (паралелно ивицама папира) коjи се не додируjу, осим евентуално jедним теменом. Написати програм коjи
// одређуjе броj правоугаоника на папиру.

int zad3(int matr[][100], int n) {
    int brojac = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matr[i][j] == 1) {

                int h = 0, w = 0;

                // visina
                while (i + h < n && matr[i + h][j] == 1)
                    h++;

                // širina
                while (j + w < n && matr[i][j + w] == 1)
                    w++;

                // provera celog pravougaonika
                int valid = 1;
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        if (matr[x][y] == 0) {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (valid) {
                    brojac++;

                    // obriši pravougaonik
                    for (int x = i; x < i + h; x++) {
                        for (int y = j; y < j + w; y++) {
                            matr[x][y] = 0;
                        }
                    }
                }
            }
        }
    }

    return brojac;
}

// ZAD 4. Ostampati potencijalne kandidate na (x,y) poziciji za sudoku
/*
2 0 3 0
0 0 2 0
0 3 1 2
1 0 4 0
*/

void sudoku() {
    int n;
    scanf("%d", &n);

    int mat[100][100];
    ucitajMatricu(mat, n*n, n*n);
    int x, y;
    scanf("%d %d", &x, &y); // pozicije koje provjeravamo

    int kandidati[n*n];
    int i, j, k;
    for (k = 0; k < n*n; k++) // setujem da su svi brojevi kandidati
        kandidati[k] = 1;
    //prolazim kroz vrstu gdje je (x,y)
    for (j = 0; j < n*n; j++) {
        int el = mat[x][j];
        if (el != 0) {
            kandidati[el - 1] = 0;
        }
    }
    //prolazim kroz kolonu gdje je (x,y)
    for (i = 0; i < n*n; i++) {
        int el = mat[i][y];
        if (el != 0) {
            kandidati[el - 1] = 0;
        }
    }
    //posmatram jedan sektor
    int i1 = n * (x / n);
    int j1 = n * (y / n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int el = mat[i1 + i][j1 + j];
            if (el != 0) {
                kandidati[el - 1] = 0;
            }
        }
    }

    for (k = 0; k < n*n; k++) {
        if (kandidati[k] == 1)
            printf("%d ", k + 1);
    }
    printf("\n");
}
// ZAD 5.
// На факултету постоjе зависности између испита коjи се полажу. На пример, да би се полагао
// испит “Програмирање 2”, претходно jе неопходно да jе положен испит “Програмирање 1”. Зависности су
// задате матрицом логичких вредности коjа представља jедну релациjу. Напиши програм коjи проверава да ли
// су испуњени следећи услови:
// • релациjа jе антирефлексивна тj. не постоjи ни jедан предмет коjи зависи сам од себе,
// • релациjа jе антисиметрична тj. не постоjе два предмета коjи међусобно зависе jедан од другог,
// • релациjа jе транзитивна тj. ако jедан предмет зависи од другог, а таj други зависи од трећег, онда jе
// неопходно да и први предмет зависи од трећег.

void zad5(int matr[][100], int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matr[j][j] == 1) {
                printf("NE");
                return;
            }
            if (i != j && matr[i][j] == 1 && matr[j][i] == 1) {
                printf("NE");
                return;
            }
            if (matr[i][j] == 1) {
                for (int k = 0; k < m; k++) {
                    if (matr[j][k] == 1 && matr[i][k] == 0) {
                        printf("NE");
                        return;
                    }
                }
            }
        }
    }

    printf("DA");
}
// ZAD 6.
// Деца су спремала приредбу у школском дворишту. Свако jе обукао костим различите боjе и
// поређали су се у квадратну матрицу. Током тачке деца су се премештала и то на веома правилне начине.
// Прво су пресликали матрицу око главне диjагонале. Затим су заротирали матрицу за 90 степени удесно (у
// смеру казаљке на сату). Након тога су jе пресликали хоризонтално и на краjу су jе пресликали око според-
// не диjагонале. Напиши програм коjи исписуjе распоред боjа дечиjих костима након сваког корака њихове
// кореографиjе.
void zad6(int matr[][100], int n, int m) {
    //transponovanje matrice
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < m; j++) {
            int temp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = temp;
        }
    }
    stampajMatricu(matr, m, n);
    //rotiranje za 90 stepeni clockwise
    int rez[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rez[j][m-i-1] = matr[i][j];
        }
    }
    stampajMatricu(rez, n, m);
    //horizontalno flipovanje matrice
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < m; j++) {
            int temp = rez[i][j];
            rez[i][j] = rez[n-i-1][j];
            rez[n-i-1][j] = temp;
        }
    }
    stampajMatricu(rez, n, m);
    //transponovanje u odnosu na sporednu dijagonalu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            int temp = rez[i][j];
            rez[i][j] = rez[n-j-1][n-i-1];
            rez[n-j-1][n-i-1] = temp;
        }
    }
    stampajMatricu(rez, n, m);
}


int main() {
     int matr[100][100];
     int m, n;
     scanf("%d%d", &n, &m);
     ucitajMatricu(matr, n, m);
    //zad1(matr, m, n);
    //zad2(matr, m, n);
    //printf("%d", zad3(matr, n));
    //sudoku();
    //zad5(matr, n, m);
    zad6(matr, n, m);


    return 0;
}