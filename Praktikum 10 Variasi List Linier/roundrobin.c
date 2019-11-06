
// ILHAM SYAHID S
// 13518028

#include "listsirkuler.h"
#include "boolean.h"
#include <stdio.h>

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
    infotype T;
    if (!IsEmpty(*L)) {
        infotype X;
        DelVLast(L, &X);
        if (X > TQ) {
        	printf("%d\n", TQ);
            X -= TQ;
            InsVFirst(L, X);
        } else {
            printf("%d\n", X);
        }
    } else {
    	printf("List kosong\n");
    }
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
    float sum = 0;
    int count = 0;
    address P = First(L);
    do
    {
        sum += + Info(P);
        count++;
        P = Next(P);
    } while (P != First(L));
    return sum/count;
}

int main() {
	infotype TQ = -1;
	int N;
	
	List L;
	CreateEmpty(&L);

	while (TQ <= 0) {
		scanf("%d", &TQ);	
	};

	char CC;
	while (true) {
		scanf("\n%c", &CC);
		if (CC == 'A') {
			scanf("%d", &N);
			if (N > 0) {
				InsVFirst(&L, N);
			}
		} else if (CC == 'D') {
			DeleteRR(&L, TQ);
		} else if (CC == 'F') {
			break;
		} else {
			printf("Kode salah\n");
		}
	}

	if (!IsEmpty(L)) {
		float avg = Average(L);
		printf("%.2f\n", avg);
	} else 
		printf("Proses selesai\n");
}