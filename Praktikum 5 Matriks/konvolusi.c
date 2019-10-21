#include <stdio.h>
#include <math.h>
#include "matriks.h"

int main()
{
	MATRIKS M1, M2, M3;
	int a, b, c, iA, jA, nilai;
	scanf("%d %d", &a, &b);
	BacaMATRIKS(&M1, a, b);
	scanf("%d", &c);
	BacaMATRIKS(&M2, c, c);

	MakeMATRIKS(a, b, &M3);

	for (int i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
	{
		for (int j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
		{
			nilai = 0;
			for (int k = GetFirstIdxBrs(M2); k <= GetLastIdxBrs(M2); k++)
			{
				iA = k - c / 2 - 1 + i;
				for (int l = GetFirstIdxKol(M2); l <= GetLastIdxKol(M2); l++)
				{
					jA = l - c / 2 - 1 + j;
					if (IsIdxEff(M1, iA, jA))
					{
						// printf("\n%d %d\n", iA, jA);
						nilai += Elmt(M2, k, l) * Elmt(M1, iA, jA);
					}
				}
			}
			Elmt(M3, i, j) = nilai;
		}
	}

	TulisMATRIKS(M3);

	return 0;
}