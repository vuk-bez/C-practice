#include <stdio.h>
#include <stdlib.h>
// ZADACI IZ FAJLA REKURZIJA3.PDF

// ZAD 1. -- Napisati rekurzivnu funkciju int insert0(int n) koja vraća prirodni broj
// koji se dobija od broja n tako što mu se između svakog para jednakih uzastopnih cifara
// umetne nula. Ukoliko u broju n nema uzastopnih ponavljanja istih cifara, broj ostaje nepromijenjen.

int zad1(int n) {
    if (n == 0) return 0;
    int cif = n % 10;
    int ostatak = zad1(n/10);
    if (cif == ostatak % 10) return ostatak*100 + cif;
    else return ostatak*10 + cif;
}

// ZAD 2. -- Napisati funkciju koja izračunava koliko
// postoji binarnih nizova dužine n u kojima nema pojave uzastopnih jedinica.
// Npr. za n = 4 izlaz je 8 (to su nizovi 0000, 0001, 0010, 0100, 0101, 1000, 1001, 1010).

int zad2(int n) {

    if (n == 1) return 2; // potencijalni kad je duzina 1 su 0 ili 1 (ukupno 2)
    if (n == 2) return 3; // potencijalni su 01 10 i 00 (ukupno 3)
    else return zad2(n-1) + zad2(n-2); // za sve ostale duzine broj kombinacija je prethodni + pretprethodni

}

// ZAD. 3. -- Dekodirati string koji je kodiran po pravilu k[tekst], gdje se tekst unutar uglastih zagrada ponavlja
// tačno k puta. Broj k je uvijek pozitivan broj.

// PAKLEN ZADATAK
int main() {
    printf("%d\n", zad1(114455));
    printf("%d\n", zad2(5));
    return 0;
}