#include <stdio.h>
#include <math.h>

// ZADACI IZ FAJLA REKURZIJA1.PDF

// ZAD. 1. -- Napisati rekurzivnu funkciju int evenDigits(int n) koja izbacuje sve parne cifre datog cijelog broja n.

int zad1(int n) {
    if (n == 0) {
        return 0;
    }

    int cif = n % 10;
    int ostatak = zad1(n/10);

    if (cif % 2 != 0) return ostatak*10 + cif;
    else return ostatak;
}

// ZAD 2. -- Napisati rekurzivnu funkciju int oddDigits(int n), koja vraća broj koji se dobije tako što se
// iza svake neparne cifre broja n doda 0.

int zad2(int n) {
    if (n == 0) {
        return 0;
    }

    int cif = n % 10;
    int ostatak = zad2(n/10);

    if (cif % 2 != 0) return (ostatak*10 + cif)*10;
    else return (ostatak*10 + cif);
}

// ZAD 3. -- Napisati rekurzivnu funkciju int digitalRoot(int target) koja izračunava digitalni korijen
// prirodnog broja n. Ako je suma cifara s(n) broja n jednocifren broj, tada je s(n) digitalni
// korijen. Ako s(n) nije jednocifren, tada se postupak ponavlja sa s(n) sve dok se ne dobije
// jednocifren broj.

int zad3(int n) {
    if (n == 0) {
        return 0;
    }
    int cif = n % 10;
    int suma = zad3(n/10) + cif;
    if (suma < 10) return suma;
    else return zad3(suma);
}

// ZAD 4.-- Napisati funkciju int pow_rek(int a, int b) koja rekurzivno izračunava b-ti stepen broja a.
// Kasnije u funkciji main za dva unijeta prirodna broja ispisati rezultat dobijen pozivom te
// funkcije.

int zad4(int a, int b) {
    if (b == 0) return 1;
    else return zad4(a,b-1)*a;
}

// ZAD. 5. -- Napisati funkciju int zbir_cif_rek(int a) koja rekurzivno izračunava zbir cifara broja a.
// Kasnije u funkciji main za unijeti celi broj ispisati rezultat dobijen pozivom te funkcije.

int zad5(int n) {
    if (n == 0) return 0;
    else return zad5(n/10) + n%10;
}

// ZAD. 6. -- Napisati funkciju int dec2bin(int n) koja rekurzivno prebacuje broj iz sistema sa osnovom
// 10, u odgovarajući broj sistema sa osnovom 2. U funkciji main testirati napisanu funkciju.
// Podrazumijevati da korisnik unosi broj za koji treba uraditi konverziju.

int zad6(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 1) return zad6(n/2)*10 + 1;
    else return zad6(n/2)*10;
}

// ZAD. 7. -- Napisati rekurzivnu funkciju double f1(int n) koja za unijeto n izračunava vrijednost
// razlomačkog izraza ilustrovanog ispod (za n = 6)

double zad7(int n) {
    if (n == 1) return 1;
    else {
        return n + 1/zad7(n-1);
    }
}

// ZAD. 8. -- Napisati rekurzivnu funkciju double f4(int i, int n) koja za unijeto n izračunava vrijednost
// korijenog izraza ilustrovanog ispod (za n = 6)

double zad8(int i,int n) {
    if (i == n) return sqrt((double)n);
    else {
        return sqrt(i + zad8(i+1,n));
    }
}

int main () {

    int n;
   // scanf("%d", &n);

    printf("%d\n", zad1(234587));
    printf("%d\n", zad2(234587));
    printf("%d\n", zad3(765));
    printf("%d\n", zad4(3,3));
    printf("%d\n", zad5(21554));
    printf("%d\n", zad6(37));
    printf("%lf\n", zad7(6));
    printf("%lf\n", zad8(1, 6));
    return 0;
}