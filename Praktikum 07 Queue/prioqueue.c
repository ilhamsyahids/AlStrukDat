// ILHAM SYAHID S
// 13518028

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah Queue, maka akses elemen : */
/* ********* Prototype ********* */
boolean IsEmpty(Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    int CountEl = (((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1);

    return (CountEl == MaxEl(Q));
}

int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{

    if (IsEmpty(Q))
    {
        return 0;
    }

    int CountEl = (((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q)) + 1); //  REMEMBER TO MOD FIRST THEN INCREMENT
    return (CountEl);
}

/* *** Kreator *** */
void CreateEmpty(Queue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));

    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else /* alokasi gagal */
    {
        MaxEl(*Q) = 0;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add(Queue *Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    }

    /* If not empty */
    else
    {

        int repeat = NBElmt(*Q);
        int idx = Tail(*Q);

        while ((Prio(X) > Prio((*Q).T[idx])) && (repeat > 0))
        {

            (*Q).T[(idx % MaxEl(*Q)) + 1] = (*Q).T[idx];

            idx--;
            repeat--;

            if (idx == 0)
            {
                idx = MaxEl(*Q);
            }
        }

        (*Q).T[(idx % MaxEl(*Q)) + 1] = X;
        Tail(*Q) = (Tail(*Q) % MaxEl(*Q)) + 1;
    }
}

void Del(Queue *Q, infotype *X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q) == 1)
    {

        Info(*X) = Info(InfoHead(*Q));
        Prio(*X) = Prio(InfoHead(*Q));
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    /* If contains more than one element */
    else
    {
        Info(*X) = Info(InfoHead(*Q));
        Prio(*X) = Prio(InfoHead(*Q));
        Head(*Q) = (Head(*Q) % MaxEl(*Q)) + 1;
    }
}

/* Operasi Tambahan */
void PrintQueue(Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    infotype Element;

    /*
    while(i != ((Tail(Q) % MaxEl(Q)) + 1 ))
    {
        printf("%d %d\n", Prio((Q).T[i]) , Info((Q).T[i]));
        i = (i % MaxEl(Q)) + 1;
    }*/

    while (!IsEmpty(Q))
    {
        Del(&Q, &Element);
        printf("%d %d\n", Prio(Element), Info(Element));
    }

    printf("#\n");
}
