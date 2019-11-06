// ILHAM SYAHID S
// 13518028

#include <stdio.h>
#include "prioqueuechar.h"

int main()
{
    PrioQueueChar Q;
    infotype x;
    int N, num, detikmin;

    scanf("%d", &N);

    CreateEmpty(&Q, N);
    detikmin = 1;
    num = 1;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %c", &Prio(x), &Info(x));
        Add(&Q, x);

        if (Prio(x) == detikmin)
        {
            for (int j = Head(Q); Prio(Elmt(Q, j)) == num; j = (j % MaxEl(Q) + 1))
            {
                printf("%d %c\n", (i + 1), Info(Elmt(Q, j)));
                Del(&Q, &x);
                num += 1;
            }
            detikmin = num;
        }
    }

    return 0;
}