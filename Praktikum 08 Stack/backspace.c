// ILHAM SYAHID S
// 13518028

#include "stackt.h"
#include <stdio.h>

int main()
{

	int n, m;
	infotype x, x2;
	Stack S1, S2;

	CreateEmpty(&S1);
	CreateEmpty(&S2);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);

		if (x != 0)
		{
			Push(&S1, x);
		}
		else
		{
			if (!IsEmpty(S1))
				Pop(&S1, &x);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &x);

		if (x != 0)
		{
			Push(&S2, x);
		}
		else
		{
			if (!IsEmpty(S2))
				Pop(&S2, &x);
		}
	}

	boolean sama = true;
	while (sama && (!IsEmpty(S1) || !IsEmpty(S2)))
	{
		Pop(&S1, &x);
		Pop(&S2, &x2);
		if ((x != x2) || (IsEmpty(S1) && !IsEmpty(S2)) || (!IsEmpty(S1) && IsEmpty(S2)))
		{
			sama = false;
		}
	}

	if (sama)
	{
		printf("Sama\n");
	}
	else
	{
		printf("Tidak sama\n");
	}

	return 0;
}