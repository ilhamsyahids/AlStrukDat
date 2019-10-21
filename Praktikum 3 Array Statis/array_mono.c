/* 	Nama 	: Ilham Syahid S
	NIM 	: 13518028
	Tgl		: 5/9/19
*/

#include "array.h"
#include <stdio.h>

int main()
{
	// KAMUS
	TabInt T;
	int cek;

	BacaIsi(&T);

	int satu = Elmt(T, 1);
	int dua = Elmt(T, 2);

	if (dua > satu)
	{
		cek = 3;
	}
	else if (dua < satu)
	{
		cek = 2;
	}
	else
	{
		cek = 1;
	}

	for (int i = 3; i <= NbElmt(T); i++)
	{
		if (Elmt(T, i) > satu)
		{
			if (cek == 1)
			{
				cek = 3;
			}
			else if (cek == 2)
			{
				cek = 0;
				break;
			}
		}
		if (Elmt(T, i) < satu)
		{
			if (cek == 1)
			{
				cek = 2;
			}
			else if (cek == 3)
			{
				cek = 0;
				break;
			}
		}
		satu = Elmt(T, i);
	}

	if (cek == 3)
	{
		printf("Array monotonik tidak mengecil\n");
	}
	else if (cek == 2)
	{
		printf("Array monotonik tidak membesar\n");
	}
	else if (cek == 1)
	{
		printf("Array monotonik statik\n");
	}
	else
	{
		printf("Array tidak monotonik\n");
	}
}