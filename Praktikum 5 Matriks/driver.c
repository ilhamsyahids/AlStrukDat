// ILHAM SYAHID S
// 13518028

#include <stdio.h>
#include "matriks.h"

int main()
{
    MATRIKS M1, M2;
    int a, b;
    //
    printf("=== M1 ===\n(input) mxn: ");
    scanf("%dx%d", &a, &b);
    printf("(input) BacaMATRIKS:\n");
    BacaMATRIKS(&M1, a, b);
    //
    printf("\n=== M2 ===\n(input) mxn: ");
    scanf("%dx%d", &a, &b);
    printf("(input) BacaMATRIKS:\n");
    BacaMATRIKS(&M2, a, b);
    //
    printf("\nTulisMATRIKS M1:\n");
    TulisMATRIKS(M1);
    //
    if (IsBujurSangkar(M1))
    {
        printf("det(M1): %f\n", Determinan(M1));
        // printf("det(M2): %f\n", Determinan(M2));
        printf("\nM1 Transpose:\n");
        Transpose(&M1);
        TulisMATRIKS(M1);
    }
    //
    if (NKolEff(M1) == NBrsEff(M2))
    {
        printf("\n\nKaliMATRIKS M1xM2:\n");
        TulisMATRIKS(KaliMATRIKS(M1, M2));
    }
    //
    printf("\n\nKaliKons M1:\n(input) X: ");
    scanf("%d", &a);
    printf("%d x M1:\n", a);
    TulisMATRIKS(KaliKons(M1, a));
    //
    printf("\n\n== M1 & M2 ==\n");
    printf("EQ: %s", (EQ(M1, M2) ? "true\n" : "false\n"));
    printf("NEQ: %s", (NEQ(M1, M2) ? "true\n" : "false\n"));
    printf("EQSize: %s", (EQSize(M1, M2) ? "true\n" : "false\n"));
}
