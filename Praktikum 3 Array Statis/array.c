// ILHAM SYAHID S
// 13518028

#include <stdio.h>
#include "boolean.h"
#include "array.h"

/* Indeks yang digunakan [IdxMin..IdxMax] */
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

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxNbEl(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
    return (IdxMax - IdxMin + 1);
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
    return Neff(T);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i >= IdxMin) && (i <= IdxMax));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
    return (NbElmt(T) == 0);
}

boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T) == (IdxMax - IdxMin + 1));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int n;
    IdxType i;

    do
    {
        scanf("%d", &n);
    } while (!((n >= 0) && (n <= MaxNbEl(*T))));

    if (n > 0)
    {
        Neff(*T) = n;
        for (i = IdxMin; i <= n; i++)
        {
            scanf("%d", &Elmt((*T), i));
        }
    }
    else
    {
        MakeEmpty(T);
    }
}
void BacaIsiTab(TabInt *T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    /* KAMUS LOKAL */
    ElType el;

    /*   ALGORITMA   */
    MakeEmpty(T);
    do
    {
        scanf("%d", &el);
        if (el != -9999)
        {
            Neff(*T)++;
            Elmt(*T, (Neff(*T))) = el;
        }
    } while ((el != -9999) && (Neff(*T) < IdxMax));
}

void TulisIsi(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
    if (IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        int i = 1;
        while (i <= NbElmt(T))
        {
            printf("[%d]%d\n", i, Elmt(T, i));
            i++;
        }
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
    if (Neff(T))
    {
        for (i = IdxMin; i < Neff(T); i++)
        {
            printf("%d,", Elmt(T, i));
        }
        printf("%d", Elmt(T, Neff(T)));
    }
    printf("]\n");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab(TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt T;
    MakeEmpty(&T);
    for (int i = IdxMin; i <= Neff(T1); i++)
    {
        Elmt(T, i) = Elmt(T1, i) + Elmt(T1, i);
    }
    Neff(T) = Neff(T1);
    return T;
}
TabInt MinusTab(TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt T;
    MakeEmpty(&T);
    for (int i = 1; i <= Neff(T1); i++)
    {
        Elmt(T, i) = Elmt(T1, i) - Elmt(T1, i);
    }
    Neff(T) = Neff(T1);
    return T;
}
TabInt KaliTab(TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt T;
    MakeEmpty(&T);
    for (int i = 1; i <= Neff(T1); i++)
    {
        TI(T)
        [i] = Elmt(T1, i) * Elmt(T1, i);
    }
    Neff(T) = Neff(T1);
    return T;
}

TabInt KaliKons(TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt T;
    MakeEmpty(&T);
    for (int i = 1; i <= Neff(Tin); i++)
    {
        TI(T)
        [i] = TI(Tin)[i] * c;
    }
    Neff(T) = Neff(Tin);
    return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    if (NbElmt(T1) != NbElmt(T2))
    {
        return false;
    }
    else
    {
        for (int i = 1; i <= NbElmt(T1); i++)
        {
            if (TI(T1) != TI(T2))
            {
                return false;
            }
        }
    }
    return true;
}

boolean IsLess(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    int min = NbElmt(T1) >= NbElmt(T2) ? NbElmt(T2) : NbElmt(T1);
    for (int i = 1; i <= min; i++)
    {
        if (Elmt(T1, i) > Elmt(T2, i))
        {
            return false;
        }
        if (Elmt(T1, i) < Elmt(T2, i))
        {
            return true;
        }
    }
    return NbElmt(T1) < NbElmt(T2);
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
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

IdxType Search2(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    boolean Found = false;
    IdxType i;
    if (!IsEmpty(T))
    {
        for (i = 1; i <= NbElmt(T); i++)
        {
            if (Elmt(T, i) == X)
            {
                Found = true;
                break;
            }
        }
    }
    return Found ? i : IdxUndef;
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
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
boolean SearchSentinel(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
    int i = MaxNbEl(T);
    Elmt(T, 0) = X;
    while (Elmt(T, i) != X)
    {
        i--;
    }
    return (i > 0);
}
/* ********** NILAI EKSTREM ********** */
ElType ValMax(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    // ElType maks = Elmt(T, IdxMin);
    // IdxType i;
    // for (i = IdxMin + 1; i <= GetLastIdx(T); i++)
    // {
    //     if (maks < Elmt(T, i))
    //         maks = Elmt(T, i);
    // }
    // return (maks);
    ElType mx;
    int i;
    mx = T.TI[IdxMin];
    for (i = IdxMin + 1; i <= GetLastIdx(T); i++)
    {
        if (mx < Elmt(T, i))
            mx = Elmt(T, i);
    }
    return (mx);
}
ElType ValMin(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{

    ElType min = Elmt(T, IdxMin);
    int i;
    for (i = IdxMin + 1; i <= GetLastIdx(T); i++)
    {
        if (min > Elmt(T, i))
            min = Elmt(T, i);
    }
    return (min);
}
IdxType IdxMaxTab(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    ElType mxi;
    int i;
    mxi = GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (Elmt(T, mxi) < Elmt(T, i))
            mxi = i;
    }
    return (mxi);
}

IdxType IdxMinTab(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    ElType mni;
    int i;
    mni = GetFirstIdx(T);
    for (i = GetFirstIdx(T) + 1; i <= GetLastIdx(T); i++)
    {
        if (Elmt(T, mni) > Elmt(T, i))
            mni = i;
    }
    return (mni);
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    *Tout = Tin;
}
TabInt InverseTab(TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    TabInt TT;
    if (!IsEmpty(TT))
    {
        Neff(TT) = NbElmt(T);
        for (int i = 1; i <= Neff(TT); i++)
        {
            Elmt(TT, i) = Elmt(T, Neff(TT) - i + 1);
        }
    }
    return TT;
}

boolean IsSimetris(TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    if (IsEmpty(T))
    {
        return true;
    }
    else
    {
        int i = 1, j = GetLastIdx(T);
        for (;;)
        {
            if (Elmt(T, i) != Elmt(T, j))
            {
                return false;
            }
            i++;
            j--;
            if (i > j)
            {
                break;
            }
        }
    }
    return true;
}

/* ********** SORTING ********** */
void MaxSortDesc(TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    IdxType i, j, idx;
    ElType temp;

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
void InsSortAsc(TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    IdxType i, j;
    ElType temp;

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
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Elmt(*T, NbElmt(*T) + 1) = X;
    Neff(*T)++;
}

void AddEli(TabInt *T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    int j;
    Neff(*T) = NbElmt(*T) + 1;
    if (i < GetLastIdx(*T))
    {
        for (j = GetLastIdx(*T); j > i; j--)
            Elmt(*T, j) = Elmt(*T, j - 1);
        Elmt(*T, i) = X;
    }
    else
    {
        Elmt(*T, i + 1) = Elmt(*T, i);
        Elmt(*T, i) = X;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, Neff(*T));
    Neff(*T)--;
}
void DelEli(TabInt *T, IdxType i, ElType *X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    IdxType idx;
    *X = Elmt(*T, i);
    for (idx = i; idx < Neff(*T); idx++)
    {
        Elmt(*T, idx) = Elmt(*T, (idx + 1));
    }
    Neff(*T)--;
}
/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik(TabInt *T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    IdxType i;

    i = Neff(*T);
    Elmt(*T, (IdxMin - 1)) = X;
    while (Elmt(*T, i) != X)
    {
        i--;
    }
    if (i == (IdxMin - 1))
    {
        Neff(*T)++;
        Elmt(*T, Neff(*T)) = X;
    }
    else
    {
        printf("nilai sudah ada\n");
    }
}
/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut(TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    IdxType i;
    if (Neff(T))
    {
        i = IdxMin;
        while ((Elmt(T, i) < X) && (i < Neff(T)))
        {
            i++;
        }
        return ((Elmt(T, i) == X) ? i : IdxUndef);
    }
    else
    {
        return IdxUndef;
    }
}
ElType MaxUrut(TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return (Elmt(T, Neff(T)));
}
ElType MinUrut(TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return (Elmt(T, IdxMin));
}
void MaxMinUrut(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}
void Add1Urut(TabInt *T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    IdxType i;

    if ((!IsEmpty(*T)) && (!IsFull(*T)))
    {
        i = IdxMin;
        while ((i <= Neff(*T)) && (Elmt(*T, i) < X))
        {
            i++;
        }
        if (i <= Neff(*T))
        {
            AddEli(T, X, i);
        }
        else
        {
            AddAsLastEl(T, X);
        }
    }
    else if (IsEmpty(*T))
    {
        Neff(*T)++;
        Elmt(*T, IdxMin) = X;
    }
}
void Del1Urut(TabInt *T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    IdxType i;
    i = IdxMin;
    while ((i < Neff(*T)) && (Elmt(*T, i) != X))
    {
        i++;
    }
    if (Elmt(*T, i) == X)
    {
        ((i == GetLastIdx(*T)) ? DelLastEl(T, &X) : DelEli(T, i, &X));
    }
}