// ILHAM SYAHID S
// 13518028

#include <stdio.h>

int main()
{
	int maks, a, b, c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a > b)
	{
		if (a > c)
		{
			maks = a;
		}
		else
		{
			maks = c;
		}
	}
	else
	{
		if (b > c)
		{
			maks = b;
		}
		else
		{
			maks = c;
		}
	}

	printf("%d\n", maks);

	return 0;
}
