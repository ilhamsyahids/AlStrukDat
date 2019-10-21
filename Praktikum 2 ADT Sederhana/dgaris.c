// Nama : Ilham Syahid S
// NIM  : 13518028

#include "garis.h"
#include <stdio.h>

int main()
{
    GARIS L;
    BacaGARIS(&L);
    TulisGARIS(L);
    printf("\n");
    printf("%.2f", PanjangGARIS(L));
    printf("\n");
    printf("%.2f", Gradien(L));
    printf("\n");
    GeserGARIS(&L, 1, 1);
    TulisGARIS(L);
    printf("\n");
    GARIS L1;
    BacaGARIS(&L1);
    printf("%.2f", Gradien(L));
    printf("\n");
    printf("%.2f", Gradien(L1));
    printf("\n");
    if (IsTegakLurus(L, L1))
    {
        printf("Tegak lurus\n");
    }
    if (IsSejajar(L, L1))
    {
        printf("Sejajar\n");
    }
}