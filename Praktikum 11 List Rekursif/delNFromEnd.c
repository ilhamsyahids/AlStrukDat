// ILHAM SYAHID S
// 13518028

#include "listrek.h"
#include <stdlib.h>

List delNFromEnd(List L, int n)
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
{
    int num = 0;
    address A[1000];
    address P = (L);
    while ((P) != Nil)
    {
        A[num] = P;
        num++;
        P = Next(P);
    }
    A[num] = Nil;
    int pos = num - n;
    if (A[pos] == L)
    {
        Dealokasi(L);
        return A[pos + 1];
    }
    else
        SetNext(A[pos - 1], A[pos + 1]);
    Dealokasi(A[pos]);
    return L;
}
