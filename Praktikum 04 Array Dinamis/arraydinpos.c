// ILHAM SYAHID S
// 13518028

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
#define ValUndef 0
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; /* type indeks */
typedef int ElType;  /* type elemen tabel */
typedef struct
{
    ElType *TI; /* memori tempat penyimpan elemen (container) */
    int Neff;   /* >=0, banyaknya elemen efektif */
    int MaxEl;  /* ukuran elemen */
} TabInt;
/* Indeks yang digunakan [IdxMin..MaxEl] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
   T.Neff  untuk mengetahui banyaknya elemen
   T.TI    untuk mengakses seluruh nilai elemen tabel
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** SELEKTOR ********** */
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define Elmt(T, i) (T).TI[(i)]
#define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
    TI(*T) = (int *)malloc((maxel + 1) * sizeof(int));
    MaxEl(*T) = maxel;
    Neff(*T) = 0;
    for (int i = 1; i <= MaxEl(*T); ++i)
    {
        Elmt(*T, i) = ValUndef;
    }
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    MaxEl(*T) = 0;
    Neff(*T) = 0;
    free(T);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return MaxEl(T);
}

IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return NbElmt(T);
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= GetFirstIdx(T)) && (i <= MaxEl(T));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmt(T) == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T) == MaxElement(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N, elm;
    do
    {
        scanf("%d", &N);
    } while (N < 0 || N > MaxElement(*T));

    if (N > 0)
    {
        Neff(*T) = N;
        for (int i = IdxMin; i <= N; i++)
        {
            scanf("%d", &Elmt(*T, i));
        }
    }
    else
    {
        MakeEmpty(T, MaxEl(*T));
    }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i;
    printf("[");
    if (NbElmt(T))
    {
        for (i = IdxMin; i < NbElmt(T); i++)
        {
            printf("%d,", Elmt(T, i));
        }
        printf("%d", Elmt(T, NbElmt(T)));
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt T;
    MakeEmpty(&T, MaxEl(T1));
    Neff(T) = Neff(T1);
    for (int i = IdxMin; i <= Neff(T1); i++)
    {
        if (plus)
        {
            Elmt(T, i) = Elmt(T1, i) + Elmt(T2, i);
        }
        else
        {
            Elmt(T, i) = Elmt(T1, i) - Elmt(T2, i);
        }
    }
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    if (NbElmt(T1) != NbElmt(T2))
    {
        return false;
    }
    else
    {
        for (int i = IdxMin; i <= NbElmt(T1); i++)
        {
            if (Elmt(T1, i) != Elmt(T2, i))
            {
                return false;
            }
        }
    }
    return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    if (!IsEmpty(T))
    {
        for (IdxType i = 1; i <= NbElmt(T); i++)
        {
            if (Elmt(T, i) == X)
            {
                return i;
            }
        }
    }
    return IdxUndef;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    if (!IsEmpty(T))
    {
        for (int i = 1; i <= NbElmt(T); i++)
        {
            if (Elmt(T, i) == X)
            {
                return true;
            }
        }
    }
    return false;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    ElType max, min;
    int i;

    // ALGORITMA
    max = Elmt(T, GetLastIdx(T));
    min = Elmt(T, GetLastIdx(T));
    for (i = GetLastIdx(T); i >= GetFirstIdx(T); i--)
    {
        if (Elmt(T, i) > max)
        {
            max = Elmt(T, i);
        }
        if (Elmt(T, i) < min)
        {
            min = Elmt(T, i);
        }
    }
    (*Max) = max;
    (*Min) = min;
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    MakeEmpty(Tout, MaxEl(Tin));
    Neff(*Tout) = Neff(Tin);
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
    {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    ElType sum = 0;

    if (Neff(T) != 0)
    {
        for (IdxType i = IdxMin; i <= Neff(T); i++)
        {
            sum += Elmt(T, i);
        }
    }
    return sum;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */ {
    int sumX = 0;
    if (Neff(T) != 0)
    {
        for (IdxType i = IdxMin; i <= Neff(T); i++)
        {
            if (X == Elmt(T, i))
            {
                sumX++;
            }
        }
    }
    return sumX;
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    if (Neff(T) != 0)
    {
        for (IdxType i = IdxMin; i <= Neff(T); i++)
        {
            if (Elmt(T, i) % 2 == 1)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    IdxType i, j, idx;
    ElType temp;

    if (!asc)
    {
        for (i = IdxMin; i < Neff(*T); i++)
        {
            idx = i;
            for (j = i; j <= Neff(*T); j++)
            {
                if (Elmt(*T, j) > Elmt(*T, idx))
                {
                    idx = j;
                }
            }
            if (idx != i)
            {
                temp = Elmt(*T, idx);
                Elmt(*T, idx) = Elmt(*T, i);
                Elmt(*T, i) = temp;
            }
        }
    }
    else
    {
        for (i = IdxMin + 1; i <= Neff(*T); i++)
        {
            temp = Elmt((*T), i);
            j = i - 1;
            while ((j >= IdxMin) && (Elmt(*T, j) > temp))
            {
                Elmt(*T, (j + 1)) = Elmt(*T, j);
                j--;
            }
            Elmt(*T, (j + 1)) = temp;
        }
    }
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{

    Elmt(*T, (NbElmt(*T) == 0) ? 1 : GetLastIdx(*T) + 1) = X;
    Neff(*T) = NbElmt(*T) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) = NbElmt(*T) - 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    MaxEl(*T) += num;
    TI(*T) = (int *) realloc(TI(*T), MaxEl(*T));
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    MaxEl(*T) -= num;
    if (Neff(*T) > MaxEl(*T)) {
        int selisih = Neff(*T) - MaxEl(*T);
        int xa;
        for (int i = 0; i < selisih; ++i)
        {
            DelLastEl(T, &xa);
        }
    }
    TI(*T) = (int *) realloc(TI(*T), MaxEl(*T));
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    MaxEl(*T) = Neff(*T);
}