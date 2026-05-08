#include <stdio.h>
#include <string.h>

int suma(int n) {
    //bazni korak
    if (n == 1) {
        return 1;
    }
    //rekurzivni korak
    else {
        return n + suma(n - 1);
    }
}

// 4. Napisati rekurzivnu funkciju koja računa najveću cifru datog cijelog broja.
int najvecaCifra(int n) {

    //bazni korak
    if (n == 0) {
        return 0;
    }
    // rekurzivni korak
    else {
        int cifra = n % 10;
        int max = najvecaCifra(n/10);
        if (cifra > max) {
            return cifra;
        } else {
            return max;
        }
    }

}
// 5. Napisati rekurzivnu funkciju koja računa n-ti element u Fibonačijevom nizu.
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }

}

//7. Napisati rekurzivnu funkciju koja nalazi minimalni element niza.

int Minimalni(int niz[], int n) {

    if (n == 0) {
        return niz[n];
    } else {
        if (niz[n] < Minimalni(niz, n-1)) {
            return niz[n];
        } else {
            return Minimalni(niz, n-1);
        }
    }

}
// 6. Napisati rekurzivnu funkciju za odredivanje NZD dva broja Euklidovim algoritmom.

int NZD(int a, int b) {
    if (a%b == 0) {
        return b;
    } else {
        NZD(b, a%b);
    }
}

// Napisati funkciju int pow_rek(int a, int b) koja rekurzivno izračunava b-ti stepen broja a.
int pow_rek(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        // ja znam koliko je a (b-1)
        return a * pow_rek(a, b-1);
    }
}
// Napisati rekurzivno funkciju koja racuna faktorijel broja
int faktorijel(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * faktorijel(n-1);
    }
}

int Podstring(char* str1, char* str2) {

    int i = 0;
    int j = 0;

    // 'a' - 97 --- 'A' 65

    for (int k=0; k<strlen(str1); k++) {
        if (str1[k] >= 'A' && str1[k] <= 'Z') {
            str1[k] = str1[k] + 32; // ('a' - 'A')
        }
    }

    for (int k=0; k<strlen(str2); k++) {
        if (str2[k] >= 'A' && str2[k] <= 'Z') {
            str2[k] = str2[k] + 32; // ('a' - 'A')
        }
    }

    while (str1[i] != '\0') {
        while (str1[i] == str2[j]) {
            j++;
            i++;
        }
        if (str2[j] == '\0') {
            return 1;
        }
        j=0;
        i++;
    }

    return 0;
}

int main() {
    char str1[100];
    char str2[100];

    gets(str1);
    gets(str2);

    printf("%d\n", Podstring(str1, str2));

    int n = 5;
    int niz[] = {4, 25, -3, 0, 7};
    printf("%d\n", Minimalni(niz, n-1));
    printf("%d\n", fibonacci(3));
    printf("%d\n", najvecaCifra(4576));
    printf("%d\n", suma(5));
    printf("%d\n", NZD(122, 25));
    printf("%d\n", pow_rek(2, 5));
    printf("%d\n", faktorijel(5));

    return 0;
}

// rekurzija <--> iterativnost(for,while)