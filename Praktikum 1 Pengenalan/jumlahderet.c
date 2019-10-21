// ILHAM SYAHID S
// 13518028

#include <stdio.h>

int main()
{
	int a, total;

	scanf("%d", &a);
	total = 0;

	for (int i = 1; i <= a; i++)
	{
		total += i;
	}

	printf("%d\n", total);
	return 0;
}
