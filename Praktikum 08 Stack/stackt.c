// ILHAM SYAHID S
// 13518028

#include "stackt.h"
#include "boolean.h"

#define Nil 0
#define MaxEl 10
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
    /* I.S. sembarang; */
    /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
    /* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
    /* Ciri stack kosong : TOP bernilai Nil */
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
{
    /* Mengirim true jika Stack kosong: lihat definisi di atas */
    return Top(S) == Nil;
}

boolean IsFull(Stack S)
{
    /* Mengirim true jika tabel penampung nilai elemen stack penuh */
    return Top(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, infotype X)
{
    /* Menambahkan X sebagai elemen Stack S. */
    /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
    /* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    if (!IsEmpty(*S))
    {
        Top(*S)++;
    }
    else
    {
        Top(*S) = 1;
    }
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X)
{
    /* Menghapus X dari Stack S. */
    /* I.S. S  tidak mungkin kosong */
    /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    *X = InfoTop(*S);
    Top(*S)--;
}