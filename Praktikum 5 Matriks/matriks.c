#include <stdio.h>
#include "matriks.h"

/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return (i <= BrsMax && i >= BrsMin) && (j <= KolMax && j >= KolMin);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
{
    /* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}

indeks GetFirstIdxKol(MATRIKS M)
{
    /* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}
indeks GetLastIdxBrs(MATRIKS M)
{
    /* Mengirimkan indeks baris terbesar M */
    return NBrsEff(M);
}
indeks GetLastIdxKol(MATRIKS M)
{
    /* Mengirimkan indeks kolom terbesar M */
    return NKolEff(M);
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
{
    /* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return (i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M));
}
ElType GetElmtDiagonal(MATRIKS M, indeks i)
{
    /* Mengirimkan elemen M(i,i) */
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
{
    /* Melakukan assignment MHsl  MIn */
    MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
    *MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
{
    /* I.S. IsIdxValid(NB,NK) */
    /* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    /* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10 */
    ElType elm;

    MakeMATRIKS(NB, NK, M);
    for (indeks i = GetFirstIdxBrs(*M); i <= NB; i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= NK; j++)
        {

            scanf("%d", &elm);
            Elmt(*M, i, j) = elm;
        }
    }
}
void TulisMATRIKS(MATRIKS M)
{
    /* I.S. M terdefinisi */
    /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
    dipisahkan sebuah spasi */
    /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10*/

    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            printf("%d", Elmt(M, i, j));
            if (j != GetLastIdxKol(M))
            {
                printf(" ");
            }
        }
        if (i != GetLastIdxBrs(M))
        {
            printf("\n");
        }
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS(MATRIKS M1, MATRIKS M2)
{
    /* Prekondisi : M1  berukuran sama dengan M2 */
    /* Mengirim hasil penjumlahan matriks: M1 + M2 */
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);

    for (indeks i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (indeks j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            Elmt(M, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }

    return M;
}

MATRIKS KurangMATRIKS(MATRIKS M1, MATRIKS M2)
{
    /* Prekondisi : M berukuran sama dengan M */
    /* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);

    for (indeks i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (indeks j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            Elmt(M, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }

    return M;
}

MATRIKS KaliMATRIKS(MATRIKS M1, MATRIKS M2)
{
    /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
    /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
    MATRIKS M;
    MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M);

    ElType elm;
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            elm = 0;
            for (indeks k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++)
            {
                elm += Elmt(M1, i, k) * Elmt(M2, k, j);
            }
            Elmt(M, i, j) = elm;
        }
    }

    return M;
}

MATRIKS KaliKons(MATRIKS M, ElType X)
{
    /* Mengirim hasil perkalian setiap elemen M dengan X */
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            Elmt(M, i, j) *= X;
        }
    }

    return M;
}

void PKaliKons(MATRIKS *M, ElType K)
{
    /* I.S. M terdefinisi, K terdefinisi */
    /* F.S. Mengalikan setiap elemen M dengan K */
    for (indeks i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
        {
            Elmt(*M, i, j) *= K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
    /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
    /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    if (NBElmt(M1) != NBElmt(M2))
        return false;
    for (indeks i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (indeks j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            if (Elmt(M1, i, j) != Elmt(M2, i, j))
            {
                return false;
            }
        }
    }
    return true;
}

boolean NEQ(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika M1 tidak sama dengan M2 */
    return (!EQ(M1, M2));
}
boolean EQSize(MATRIKS M1, MATRIKS M2)
{
    /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
    /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return (NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt(MATRIKS M)
{
    /* Mengirimkan banyaknya elemen M */
    return NBrsEff(M) * NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar(MATRIKS M)
{
    /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
    return (GetLastIdxBrs(M) == GetLastIdxKol(M));
}

boolean IsSimetri(MATRIKS M)
{
    /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
    dan untuk setiap elemen M, M(i,j)=M(j,i) */
    if (!IsBujurSangkar(M))
    {
        return false;
    }
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            if (Elmt(M, i, j) != Elmt(M, j, i))
            {
                return false;
            }
        }
    }

    return true;
}

boolean IsSatuan(MATRIKS M)
{
    /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (!IsBujurSangkar(M))
    {
        return false;
    }
    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            if (i == j)
            {
                if (Elmt(M, i, j) != 1)
                {
                    return false;
                }
            }
            else
            {
                if (Elmt(M, i, j) != 0)
                {
                    return false;
                }
            }
        }

    return true;
}

boolean IsSparse(MATRIKS M)
{
    /* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    float count;

    for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        for (indeks j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
        {
            if (Elmt(M, i, j) != 0)
            {
                count++;
            }
        }
    }

    return ((count / NBElmt(M)) <= 0.05);
}

MATRIKS Inverse1(MATRIKS M)
{
    /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
    MATRIKS M1;
    CopyMATRIKS(M, &M1);
    for (indeks i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
    {
        for (indeks j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
        {
            Elmt(M1, i, j) *= -1;
        }
    }

    return M1;
}

float Determinan(MATRIKS M)
{
    float det;
    if (NBrsEff(M) == 1)
    {
        det = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
    }
    else
    {
        det = 0;
        for (indeks i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
        {
            MATRIKS Minor;
            MakeMATRIKS((NBrsEff(M) - 1), (NKolEff(M) - 1), &Minor);
            indeks iM, jM, iMi, jMi;
            iMi = GetFirstIdxBrs(Minor);
            for (iM = GetFirstIdxBrs(M); iM <= GetLastIdxBrs(M); iM++)
            {
                if (iM != i)
                {
                    jMi = GetFirstIdxKol(Minor);
                    for (jM = GetFirstIdxKol(M); jM <= GetLastIdxKol(M); jM++)
                    {
                        if (jM != GetFirstIdxKol(M))
                        {
                            Elmt(Minor, iMi, jMi) = Elmt(M, iM, jM);
                            jMi++;
                        }
                    }
                    iMi++;
                }
            }
            det += (i % 2 == 1 ? 1 : -1) * Elmt(M, i, GetFirstIdxKol(M)) * Determinan(Minor);
        }
    }
    return det;
}

void PInverse1(MATRIKS *M)
{
    /* I.S. M terdefinisi */
    /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    for (indeks i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
        {
            Elmt(*M, i, j) *= -1;
        }
    }
}

void Transpose(MATRIKS *M)
{
    /* I.S. M terdefinisi dan IsBujursangkar(M) */
    /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    ElType temp;
    MATRIKS M1;
    CopyMATRIKS(*M, &M1);
    for (indeks i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
    {
        for (indeks j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
        {
            Elmt(M1, i, j) = Elmt(*M, j, i);
        }
    }

    CopyMATRIKS(M1, M);
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    float count=0, nilai=0;
    for (indeks j = GetFirstIdxKol(M); j<=GetLastIdxKol(M);j++) {
        nilai += Elmt(M, i, j);
        count++;
    }

    return (nilai/count);
}

float RataKol (MATRIKS M, indeks j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
    float count=0, nilai=0;
    for (indeks i = GetFirstIdxBrs(M); i<=GetLastIdxBrs(M);i++) {
        nilai += Elmt(M, i, j);
        count++;
    }

    return (nilai/count);   
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    ElType Max = Elmt(M, i, GetFirstIdxKol(M));
    ElType Min = Elmt(M, i, GetFirstIdxKol(M));
    for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
    {
        if (Elmt(M, i, j) >= Max) {
            Max = Elmt(M, i, j);
        } else if (Elmt(M, i, j) <= Min) {
            Min = Elmt(M, i, j);
        } 
    }

    (*max) = Max;
    (*min) = Min;
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    ElType Max = Elmt(M, GetFirstIdxBrs(M), j);
    ElType Min = Elmt(M, GetFirstIdxBrs(M), j);
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        if (Elmt(M, i, j) >= Max) {
            Max = Elmt(M, i, j);
        } else if (Elmt(M, i, j) <= Min) {
            Min = Elmt(M, i, j);
        } 
    }

    (*max) = Max;
    (*min) = Min;
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    int count=0;
    for (int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
    {
        if (Elmt(M, i, j) == X) {
            count++;
        } 
    }
    
    return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    int count=0;
    for (int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
    {
        if (Elmt(M, i, j) == X) {
            count++;
        } 
    }
    
    return count;
}