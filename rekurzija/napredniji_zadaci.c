#include <stdio.h>
#include <math.h>

//Zadaci iz fajla rekurzija2.pdf

// ZAD 1.Napisati rekurzivne varijante funkcija strcpy, strncpy, strcmp.

void strcpyR(char* dest, char* src) {
    // src = "principi\0" ---> dest ""

    if (*src == '\0') {
        *dest = '\0';
        return;
    } else {
        *dest = *src;
        strcpyR(dest + 1, src + 1);
    }

}

void strncpyR(char* dest, char* src, int n) {
    if (*src == '\0') {
        *dest = '\0';
        return;
    } else if (n == 0) {
        *dest = *src;
        strncpyR(dest+1, src+1, 0);
    } else {
        strncpyR(dest, src+1, n-1);
    }
}

int strcmpR(char* first, char* second) {
    if (*first == *second && *first != '\0' && *second != '\0') {
        return strcmpR(first + 1,second + 1);
    } else if (*first > *second) {
        return 1;
    } else if (*second > *first) {
        return -1;
    } else if (*first == '\0' && *second == '\0') {
        return 0;
    } else {
        return -1;
    }
}

// ZAD. 2. Napisati rekurzivnu funkciju koja provjerava da li je dati string palindrom

int palindrom(char* str, int n) {

    if (n <= 1) {
        return 1;
    } else if (*str == *(str + n-1)) {
        return palindrom(str+1, n-2);
    } else {
        return 0;
    }
}

//ZAD 3. -- Napisati rekurzivnu funkciju void preuredi(int* a, int n) koja niz a dužine n preuređuje tako da parni
// elementi budu ispred neparnih. Npr. od niza 1, 2, 3, 4, 5, 6, 7 treba dobiti niz 2, 4, 6, 1, 3, 5, 7.
// --- NE RADIIII -----
void preuredi(int* a, int n) {
    if (n == 1) {
        return;
    }

    int l = a[0];
    int r = a[n-1];

    if (l % 2 == 1 && r % 2 == 1) {
        preuredi(a, n-1);
    } else if (l % 2 == 1 && r % 2 == 0) {
        a[0] = r;
        a[n-1] = l;
        preuredi(a+1, n-2);
    } else if (l % 2 == 0 && r % 2 == 1) {
        preuredi(a+1, n-2);
    } else {
        preuredi(a+1, n-1);
    }
}

// ZAD 4. -- Napisati rekurzivnu implementaciju ovog načina stepenovanja broja x brojem n.

int stepenovanje(int x, int n) {
    if (n == 1) {
        return x;
    } else if ( n%2 == 1) {
        return x*stepenovanje(x*x, (n-1)/2);
    } else {
        return stepenovanje(x*x, n/2);
    }
}

// ZAD. 5. Napisati rekurzivnu varijantu funkcije int atoi(char* s) koja dati string pretvara u odgovarajući cijeli broj.

int atoiR(char* s, int n) {
    if (n == 1) {
        return *s - '0';
    }
    else {
        return atoiR(s, n-1)*10 + (s[n-1] - '0');
    }
}
int main() {
    char src[100] = "ANA";
    char dest[100] = "principi";
    //strcpyR(dest, src); --- test za zad 1.
    //strncpyR(dest, src, 3);
    //printf("%s", dest);
    //printf("%d", palindrom(src, 3));
    //preuredi(niz, 7);
    //printf("%d", stepenovanje(2, 7));
    printf("%d", atoiR("256", 3));
    return 0;
}
