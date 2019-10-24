// ILHAM SYAHID S
// 13518028

/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
{
    /* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty(List *L)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    /* Mengirimkan address hasil alokasi sebuah elemen */
    /* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
    /* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
    /* Jika alokasi gagal, mengirimkan Nil */
    ElmtList *E = (ElmtList *)malloc(sizeof(ElmtList));

    if (E != Nil)
    {
        Info(E) = X;
        Next(E) = Nil;
        return E;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi(address *P)
{
    /* I.S. P terdefinisi */
    /* F.S. P dikembalikan ke sistem */
    /* Melakukan dealokasi/pengembalian address P */
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    /* Mencari apakah ada elemen list dengan Info(P)= X */
    /* Jika ada, mengirimkan address elemen tersebut. */
    /* Jika tidak ada, mengirimkan Nil */

    boolean found = false;
    address elmt = First(L);

    if (!IsEmpty(L))
    {
        while ((!found) && (elmt != Nil))
        {
            if (Info(elmt) == X)
            {
                found = true;
            }
            else
            {
                elmt = Next(elmt);
            }
        }
    }

    return elmt;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X)
{
    /* I.S. L mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
{
    /* I.S. List L tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast(List *L, infotype *X)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
    /*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
    /* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
    /*      P sudah dialokasi  */
    /* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, address P)
{
    /* I.S. Sembarang, P sudah dialokasi  */
    /* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* First element yg baru adalah suksesor elemen pertama yang lama */
    address X = First(*L);
    if (Next(X) == Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        First(*L) = Next(X);
    }
    *P = X;
}

void DelP(List *L, infotype X)
{
    /* I.S. Sembarang */
    /* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
    /* Maka P dihapus dari list dan di-dealokasi */
    /* Jika ada lebih dari satu elemen list dengan Info bernilai X */
    /* maka yang dihapus hanya elemen pertama dengan Info = X */
    /* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
    /* List mungkin menjadi kosong karena penghapusan */
    address P = Search(*L, X);

    if (P != Nil)
    {
        address prev = First(*L);

        if (prev == P)
        {
            DelFirst(L, &P);
        }
        else
        {
            while (Next(prev) != P)
            {
                prev = Next(prev);
            }
            DelAfter(L, &P, prev);
        }
    }
    Dealokasi(&P);
}
void DelLast(List *L, address *P)
{
    /* I.S. List tidak kosong */
    /* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
    /*      Elemen list berkurang satu (mungkin menjadi kosong) */
    /* Last element baru adalah predesesor elemen terakhir yg lama, */
    /* jika ada */
    *P = First(*L);
    if (Next(*P) == Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        address prev = *P;
        while (Next(Next(prev)) != Nil)
            prev = Next(prev);

        DelAfter(L, P, prev);
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    /* I.S. List tidak kosong. Prec adalah anggota list  */
    /* F.S. Menghapus Next(Prec): */
    /*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
        Next(Prec) = Next(Next(Prec));
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo(List L)
{
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    if (!IsEmpty(L))
    {
        address P = First(L);
        do
        {
            printf("%d", Info(P));
            P = Next(P);
            if (P != Nil)
                printf(",");
        } while (P != Nil);
    }
    printf("]");
}

int NbElmt(List L)
{
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int count = 0;
    if (!IsEmpty(L))
    {
        address P = First(L);
        while (Next(P) != Nil)
        {
            count++;
            P = Next(P);
        }
        count++;
    }

    return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max(List L)
{
    /* Mengirimkan nilai Info(P) yang maksimum */
    address P = First(L);
    infotype mx = Info(P);

    do
    {
        P = Next(P);
        if (Info(P) > mx)
            mx = Info(P);
    } while (Next(P) != Nil);

    return mx;
}
/****************** PROSES TERHADAP LIST ******************/
void Konkat1(List *L1, List *L2, List *L3)
{
    /* I.S. L1 dan L2 sembarang */
    /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
    /* Konkatenasi dua buah list : L1 dan L2    */
    /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
    /* dan L1 serta L2 menjadi list kosong.*/
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    address X;

    CreateEmpty(L3);
    if (!IsEmpty(*L1))
    {
        address P = First(*L1);
        First(*L3) = P;
        while (Next(P) != Nil)
        {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L2);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}