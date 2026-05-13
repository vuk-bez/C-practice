#include <stdio.h>

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
    return (i & mask);
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
    mask = mask << k;
    if (i & mask == i)
}
int main() {


    return 0;
}
