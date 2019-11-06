#include "jam.h"
#include <stdio.h>

int main()
{
    /* KELOMPOK BACA/TULIS                                               */
    JAM J1, J2;
    printf("Baca jam 1 = ");
    BacaJAM(&J1);

    printf("Baca jam 2 = ");
    BacaJAM(&J2);

    printf("Tulis jam 1 = ");
    TulisJAM(J1);
    printf("\n");

    printf("Tulis jam 2 = ");
    TulisJAM(J2);
    printf("\n");

    printf("Jam 1 ke detik = %ld \n", JAMToDetik(J1));
    printf("Jam 2 ke detik = %ld \n", JAMToDetik(J2));

    /* KELOMPOK OPERASI TERHADAP TYPE                                    */
    printf("Jam 1");
    if (JEQ(J1, J2))
    {
        printf(" sama dengan");
    }
    if (JNEQ(J1, J2))
    {
        printf(" tidak sama yaitu");
        if (JGT(J1, J2))
        {
            printf(" lebih besar dari");
        }
        if (JLT(J1, J2))
        {
            printf(" lebih kecil dari");
        }
    }
    printf(" jam 2\n");

    /* KELOMPOK KONVERSI TERHADAP TYPE                                   */
    long detik;
    printf("Masukan detik = ");
    scanf("%ld", &detik);
    printf("Menjadi jam = ");
    TulisJAM(DetikToJAM(detik));
    printf("\n");

    /* *** Operator aritmatika JAM *** */
    printf("1 detik setelah jam 1 = ");
    TulisJAM(NextDetik(J1));
    printf("\n");
    printf("1 detik sebelum jam 1 = ");
    TulisJAM(PrevDetik(J1));
    printf("\n");

    int N;
    printf("Masukkan N: ");
    scanf("%d", &N);
    printf("N detik setelah jam 1 = ");
    TulisJAM(NextNDetik(J1, N));
    printf("\n");

    /* *** Kelompok Operator Aritmetika *** */
    printf("Durasi antara jam 1 ke jam 2 = ");
    printf("%ld", Durasi(J1, J2));
    printf(" detik\n");

    return 0;
}