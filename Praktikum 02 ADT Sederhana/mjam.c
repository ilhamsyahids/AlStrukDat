// Nama 	: Ilham Syahid S
// NIM 		: 13518028
// Tanggal 	: 29 Agu 2019

#include "jam.h"
#include <stdio.h>

int main()
{
	int n, i;
	JAM J1, J2, maksJ, minJ;

	Hour(maksJ) = 0;
	Minute(maksJ) = 0;
	Second(maksJ) = 0;

	Hour(minJ) = 23;
	Minute(minJ) = 59;
	Second(minJ) = 59;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("[%d]\n", (i + 1));
		BacaJAM(&J1);
		BacaJAM(&J2);
		if (JGT(J1, J2))
		{
			printf("%ld\n", Durasi(J2, J1));
		}
		else
		{
			printf("%ld\n", Durasi(J1, J2));
		}

		if (JGT(J1, maksJ))
		{
			maksJ = J1;
		}
		if (JGT(J2, maksJ))
		{
			maksJ = J2;
		}

		if (JLT(J1, minJ))
		{
			minJ = J1;
		}
		if (JLT(J1, minJ))
		{
			minJ = J2;
		}
	}

	TulisJAM(minJ);
	printf("\n");
	TulisJAM(maksJ);
	printf("\n");
}
