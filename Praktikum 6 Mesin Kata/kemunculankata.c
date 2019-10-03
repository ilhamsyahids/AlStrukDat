// ILHAM SYAHID S
// 13518028

#include "mesinkata.h"
#include <stdio.h>

void Salin(Kata *dest, Kata src)
/* Menyalin kata
   I.S. : dest sembarang, src sebuah kata yang valid
   F.S. : dest merupakan kata dengan panjang yang sama dengan src
          dan tiap karakter dest sama dengan src */
{
	(*dest) = src;
}

int main()
{
	Kata Pertama;
	int hitung = 0;
	int a = 1;
	int b = 1;
	int j;
	boolean sama;
	STARTKATA();
	Salin(&Pertama, CKata);
	ADVKATA();

	while (!EndKata)
	{
		for (int i = 1; i <= CKata.Length - Pertama.Length + 1; i++)
		{
			sama = false;
			j = i;
			while (!(sama) && (j <= i + Pertama.Length - 1))
			{
				if (CKata.TabKata[j] != Pertama.TabKata[j - i + 1])
					sama = true;
				else
					j++;
			}

			if (j == i + Pertama.Length)
				hitung++;
		}
		ADVKATA();
	}
	printf("%d\n", hitung);

	return 0;
}