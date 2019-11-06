// ILHAM SYAHID S
// 13518028

#include "boolean.h"
#include "array.h"
#include <stdio.h>

int main()
{
    TabInt T, T1, T2;
    BacaIsiTab(&T1);
    BacaIsiTab(&T2);
    T = PlusTab(T1, T2);
    TulisIsiTab(T1);
    T2 = InverseTab(T1);
    TulisIsiTab(T2);
    TulisIsi(T2);
    T = MinusTab(T1, T2);
    TulisIsi(T);
    T = KaliTab(T1, T2);
    TulisIsi(T);
    T = KaliKons(T1, 2);
    TulisIsi(T);
    if (SearchSentinel(T1, 2))
    {
        printf("ADA");
    }
    else
    {
        printf("TIDAK");
    }
    IdxType Max = IdxMaxTab(T);
    printf("%d", Max);
    ValMax(T);
}