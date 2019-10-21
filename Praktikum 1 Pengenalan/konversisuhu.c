// ILHAM SYAHID S
// 13518028

#include <stdio.h>

int main()
{
	char T;
	float C, kon;

	scanf("%f\n", &C);
	scanf("%c", &T);

	if (T == 'R')
	{
		kon = (4.00 / 5.00) * C;
	}
	else if (T == 'F')
	{
		kon = ((float)9 / (float)5 * C) + 32;
	}
	else
	{
		kon = C + 273.15;
	}

	printf("%.2f\n", kon);

	return 0;
}
