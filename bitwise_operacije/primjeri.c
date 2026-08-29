#include <stdio.h>

//4 bajta - 32 bita (int) 000000 ..... 00000001

// ZAD. 1. -- Napisati funkciju koja vraća najmanje značajan bit (LSB) cijelog broja.
// Drugim riječima, odrediti da li je posljednji bit broja 0 ili 1.

int zad1(int n) {
    int mask = 1; // 0...0 0...0 0...0 0...1
    return (n & mask); // konjukcija od n i mask
}

// ZAD 2. -- Napisati funkciju koja za dati broj i poziciju k vraća vrijednost bita na toj poziciji.
// Pozicije se broje od 0 (najmanje značajan bit).

int zad2(int i, int k) {
    int mask = 1; // 0...0 0...0 0...0 0...1
    mask = mask << k; // 0...0 0...1(k-ta pozicija) 0...0 0...0
    return (i & mask) >> k; // 0...0 0...1 0...0 0...0
}

// ZAD 3. -- Napisati funkciju koja postavlja (setuje) k-ti bit broja na 1, bez obzira na njegovu prethodnu vrijednost.

int zad3(int i, int k) {
    int mask = 1; // 0...0 0...0 0...0 0...1
    mask = mask << k;// 0...0 0...0 1(k-ta pozicija)...0 0...0
    return (i | mask);// x...x x...x 1...x x...x (na k-toj poziciji je 1)
}

// ZAD. 4. -- Napisati funkciju koja mijenja vrijednost k-tog bita (ako je 1 postaje 0, ako je 0 postaje 1).

int zad4(int i, int k) {
    int mask = 1;
    mask = mask << k; //0...0 0...0 1...0 0...0   0^0 --> 0 0^1 ---> 1 1^0 --> 1 1^1 ---> 0
    return (mask ^ i);//x...x x...x  ...x x...x
}

// ZAD. 5. -- Napisati funkciju koja pronalazi indeks najvišeg bita koji ima vrijednost 1 u binarnom zapisu broja. Ako broj nema jedinica, vratiti -1.

int  zad5(int n) {

    int Ind = -1;
    for (int i = 0; i < 32; i++) { // x...x x...x x...x x...x
        int mask = 1;
        mask = mask << i;
        if (n & mask)
            Ind = i;
    }
    return Ind;
}

// ZAD 6. -- Napisati funkciju koja pronalazi indeks najnižeg bita koji ima vrijednost 1 u binarnom zapisu broja.

int zad6(int n) {
    for (int i = 0; i < 32; i++) { // x...x x...x x...x ....1000
        int mask = 1;
        mask = mask << i;
        if (n & mask) {
            return i;
        }
    }
    return -1;
}

// ZAD 7. -- Napisati funkciju koja broji koliko nula ima u binarnom zapisu broja (na nivou tipa int).

int zad7(int n) {
    int brojac = 0;
    for (int i = 0; i < 32; i++) {
        int mask = 1;
        mask = mask << i;
        if (!(n & mask)) brojac++;
    }
    return brojac;
}

// ZAD. 8. -- Napisati funkciju koja broji koliko jedinica ima u binarnom zapisu broja.

int zad8(int n) {
    int brojac = 0;
    for (int i = 0; i < 32; i++) {
        int mask = 1;
        mask = mask << i;
        if (n & mask) brojac++;
    }
    return brojac;
}

// ZAD. 9. -- Napisati funkciju koja invertuje sve bitove broja (0 postaje 1, a 1 postaje 0).

int zad9(int n) {

    for (int i = 0; i < 32; i++) {
       int mask = 1;
       mask = mask << i;
       n = n ^ mask;
   }
    return n;

}

// ZAD. 10. -- Napisati funkciju koja rotira bitove broja udesno za jedno mjesto.
// Najmanje značajan bit prelazi na najvišu poziciju.

int zad10(int n) {
    if (zad2(n, 0)) {
        n = n >> 1;
        n = n | 128; // 0...0 0...0 0...0 1...0
        return n;
    } else return n >> 1;
}

// ZAD 11. -- Napisati funkciju koja rotira bitove broja udesno za k pozicija.

int zad11(int n, int k) {
    for (int i = 0; i < k; i++) {
        n = zad10(n);
    }
    return n;
}

// ZAD 12. -- Napisati funkciju koja provjerava da li je broj paran ili neparan koristeći bitwise operacije.

void zad12(int n) {
    int mask = 1;
    if (mask & n) printf("Neparan");
    else printf("Paran");
    printf("\n");
}

// ZAD 13. -- Napisati funkciju koja ispisuje binarni zapis datog cijelog broja (32 bita).

void zad13(int n) {
    for (int i = 31; i >= 0; i--) {
        int mask = 1;
        mask = mask << i;
        if (n & mask) printf("1");
        else printf("0");
    }
    printf("\n");
}

// ZAD. 14. -- Napisati funkciju koja pronalazi poziciju prve jedinice u binarnom zapisu broja (od lijeve ka desnoj strani). Rezultat vratiti kao indeks + 1.

int zad14(int n) {
    for (int i = 31; i >= 0; i--) {
        int mask = 1;
        mask = mask << i;
        if (n & mask) return i + 1;
    }
    return -1;
}

// ZAD. 15. -- Napisati funkciju koja vraća najznačajniji bit broja (MSB).

int zad15(int n) {
    int mask = 1;
    return (n >> 31) & mask;
}
int main() {

   // printf("%d\n", zad2(5, 2));
   // printf("%d\n", zad5(-8));
   // printf("%d\n", zad6(8));
  //  printf("%d\n", zad7(-7));
   // printf("%d\n", zad8(-7));
    printf("%d\n", zad9(-13));
    printf("%d\n", zad10(-7));
    printf("%d\n", zad11(-7, 3));
    zad12(8);
    zad13(-7);
    printf("%d\n", zad14(-7));
    printf("%d\n", zad15(-7));
    return 0;

}

