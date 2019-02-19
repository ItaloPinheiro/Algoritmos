#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
    	quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
int main(){
	int i, v[5] = {8, 6, 7, 2, 3};
	quick_sort(v, 0, 4);
	for(i = 0;i < 5; i++)
		printf("%d ", v[i]);
	lista.sort();
	system("pause");
}
