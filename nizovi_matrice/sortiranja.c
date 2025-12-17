// sortiranja osnovnog tipa slozenosti n na kvadrat (od najmanjed do najveceg)
#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) { // tip selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // fixiramo prvu poziciju
        for (int j = i + 1; j < n; j++) { // uporedjujemo prvu sa svim ostalim 
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i]; // kada nadjemo najmanji, zamijeni ga sa prvim i tako sve do kraja niza
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertionSort(int arr[], int n) // tip insertion sort
{
    for (int i = 1; i < n; ++i) {
        int poredbenik = arr[i]; // uzimamo jedan element i fiksiramo ga
        int j = i - 1;

        while (j >= 0 && arr[j] > poredbenik) { //sad svaki element sa indeksom manjim od fiksiranog, poredi sa vrijednoscu fiksiranog
            arr[j + 1] = arr[j]; // ako se nadje neki koji je manji, pomjeraj ga ulijevo sve dok vazi uslov 
            j --;
        }
        arr[j + 1] = poredbenik;
    }
}

void bubbleSort(int arr[], int n){ // tip bubble sort
    int i, j;
    int zamijenjeni;
    for (i = 0; i < n - 1; i++) {
        zamijenjeni = 1; // indikator da li je doslo do promjene
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // gura najveci do kraja, uporedjujuci par po par
                
                int temp = arr[j]; // mijenja im pozicije ako je ispunjen uslov
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                zamijenjeni = 0;
            }
        }

        // ako kroz cijeli jedan ciklus nije doslo do promjene pozicije, prekini for jer su sortirani
        if (zamijenjeni)
            break;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    printf("Pocetni niz: ");
    printArray(arr, n);
    
    //selectionSort(arr, n); // testiranje bilo kog tipa sortiranja
    //insertionSort(arr, n);
    bubbleSort(arr, n);
    
    printf("Sortirani niz: ");
    printArray(arr, n);
    
    return 0;
}