#include <stdio.h>
#include <stdlib.h>


int shellSort(int *vet, int size) {
    int i , j , value, c=0;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                c++;
            }
            vet [j + gap] = value;
        }
    }
    return c;
}
