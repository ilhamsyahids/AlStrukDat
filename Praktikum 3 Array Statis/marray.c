/* 	Nama 	: Ilham Syahid S
	NIM 	: 13518028
	Tgl		: 5/9/19
*/

#include "array.h"
#include <stdio.h>

int main() {
	// KAMUS
	TabInt T;
	int x, count = 0;

	// ALGORITMA
	BacaIsi(&T);
	scanf("%d", &x);
	TulisIsiTab(T);
	printf("\n");

	for(int i = 1; i<= NbElmt(T); i++) {
		if (Elmt(T, i) == x) {
			count++;
		}
	}

		printf("%d\n", count);
	if (count == 0) {
			printf("%d tidak ada\n", x);
	} else {
			printf("%d\n", Search1(T,x));
	}

	if (ValMax(T) == x) {
		printf("maksimum\n");
	}
	if (ValMin(T) == x) {
		printf("minimum\n");
	}

	InsSortAsc(&T);
	int sum =NbElmt(T);
	int median;
	if (sum%2 == 0 ) {
		median = Elmt(T, sum/2);
	} else {
		median = Elmt(T, sum/2 +1);
	}
	if (median == x) {
		printf("median\n");
	}
}