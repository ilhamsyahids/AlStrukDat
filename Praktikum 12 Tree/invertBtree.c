// ILHAM SYAHID S
// 13518028

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void InvertBtree(BinTree *P)
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */

{
	if (IsBiner(*P))
	{
		BinTree temp;
		temp = Left(*P);
		Left(*P) = Right(*P);
		Right(*P) = temp;
		InvertBtree(&Left(*P));
		InvertBtree(&Right(*P));
	}
	else if (IsUnerLeft(*P))
	{
		Right(*P) = Left(*P);
		Left(*P) = Nil;
		InvertBtree(&Right(*P));
	}
	else if (IsUnerRight(*P))
	{
		Left(*P) = Right(*P);
		Right(*P) = Nil;
		InvertBtree(&Left(*P));
	}
}