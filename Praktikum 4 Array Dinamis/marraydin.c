// ILHAM SYAHID S
// 13518028

#include "arraydin.h"
#include <stdio.h>

void A(TabInt T)
{
	printf("%d ", MaxElement(T));
	TulisIsiTab(T);
	printf("\n");
}

int main()
{
	TabInt T;
	int Q, op, mxEl;
	ElType num;

	scanf("%d", &mxEl);
	MaxEl(T) = mxEl;
	BacaIsi(&T);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &num);
			if (IsFull(T))
			{
				printf("array sudah penuh\n");
			}
			else
			{
				AddAsLastEl(&T, num);
				A(T);
			}
		}
		else if (op == 2)
		{
			scanf("%d", &num);
			GrowTab(&T, num);
			A(T);
		}
		else if (op == 3)
		{
			scanf("%d", &num);
			if (MaxElement(T) < num)
			{
				printf("array terlalu kecil\n");
			}
			else
			{
				ShrinkTab(&T, num);
				A(T);
			}
		}
		else
		{
			CompactTab(&T);
			A(T);
		}
	}

	return 0;
}
