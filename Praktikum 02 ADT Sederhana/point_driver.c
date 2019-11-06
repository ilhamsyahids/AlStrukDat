#include "point.h"
#include <stdio.h>

int main()
{
    POINT P;

    // Test Baca/tulis
    printf("Masukkan nilai absis dan ordinat dari P1: \n");
    BacaPOINT(&P);
    printf("Titik yang terbaca ");
    TulisPOINT(P);

    // Test keberadaan titik P
    if (IsOrigin(P))
    {
        printf(" adalah titik origin\n");
    }
    else if (IsOnSbX(P))
    {
        printf(" berada pada Sb-X\n");
    }
    else if (IsOnSbY(P))
    {
        printf(" berada pada Sb-Y\n");
    }
    else
    {
        printf(" berada di kuadran %d\n", Kuadran(P));
    }
    printf("\n");

    // Test operasi thd type

    // Tambah 1
    printf("Jika absis P1 ditambah satu menjadi ");
    TulisPOINT(NextX(P));
    printf("\n");
    printf("\n");
    printf("Jika ordinat P1 ditambah satu menjadi ");
    TulisPOINT(NextY(P));
    printf("\n");
    printf("\n");

    // Salinan geser
    float dx, dy;
    printf("Jika P1 digeser sejajar sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("dan jika P1 digeser sejajar sumbu y sebesar = ");
    scanf("%f", &dy);
    printf("Setelah digeser akan menjadi ");
    TulisPOINT(PlusDelta(P, dx, dy));
    printf("\n");
    printf("\n");

    // Jarak
    printf("Jarak P1 ");
    TulisPOINT(P);
    printf(" terhadap titik (0,0) adalah %.2f\n", Jarak0(P));
    printf("\n");

    // Geser
    printf("Geser P1 sejajar sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("Geser P1 sejajar sumbu y sebesar = ");
    scanf("%f", &dy);
    TulisPOINT(P);
    printf(" setelah digeser P1 menjadi ");
    Geser(&P, dx, dy);
    TulisPOINT(P);
    printf("\n");
    printf("\n");

    // Geser thd sb-x
    POINT PX = P, PY = P;
    printf("P1 digeser ke Sb-X = ");
    GeserKeSbX(&PX);
    TulisPOINT(PX);
    printf("\n");

    // Geser thd sb-y
    printf("P1 digeser ke Sb-Y = ");
    GeserKeSbY(&PY);
    TulisPOINT(PY);
    printf("\n");

    // Pencerminan
    printf("P1 dicerminkan terhadap Sb-X = ");
    Mirror(&P, true);
    TulisPOINT(P);
    printf("\n");
    printf("P1 dicerminkan terhadap Sb-Y = ");
    Mirror(&P, false);
    TulisPOINT(P);
    printf("\n");

    // Putar
    float deg;
    printf("P1 di putar sebesar = ");
    scanf("%f", &deg);
    TulisPOINT(P);
    Putar(&P, deg);
    printf(" setelah diputar %.2f deg = ", deg);
    TulisPOINT(P);
    printf("\n");
    printf("\n");

    // Test operasi relasional thdp POINT
    POINT P2;
    printf("Masukkan nilai absis dan ordinat dari P2: \n");
    BacaPOINT(&P2);
    printf("Titik yang terbaca ");
    TulisPOINT(P2);
    printf("\n");

    printf("P1");
    TulisPOINT(P);
    printf(" dengan P2");
    TulisPOINT(P2);
    if (NEQ(P, P2))
    {
        printf(" tidak sama\n");
    }
    if (EQ(P, P2))
    {
        printf(" sama\n");
    }

    return 0;
}