// ILHAM SYAHID S
// 13518028

#include "mesintoken.h"
#include "stackt.h"
#include <math.h>
#include <stdio.h>

int main()
{
	STARTTOKEN();
	Stack S1;
	int op1, op2;

	CreateEmpty(&S1);

	if (EndToken)
	{
		printf("Ekspresi kosong\n");
	}
	else
	{
		int x;
		while (!EndToken)
		{
			if (CToken.tkn == 'b')
			{
				printf("%d\n", CToken.val);
				Push(&S1, CToken.val);
			}
			else
			{
				Pop(&S1, &op2);
				Pop(&S1, &op1);
				if (CToken.tkn == '+')
				{
					x = op1 + op2;
				}
				else if (CToken.tkn == '-')
				{
					x = op1 - op2;
				}
				else if (CToken.tkn == '*')
				{
					x = op1 * op2;
				}
				else if (CToken.tkn == '/')
				{
					x = op1 / op2;
				}
				else
				{
					x = pow(op1, op2);
				}

				printf("%d %c %d\n", op1, CToken.tkn, op2);
				printf("%d\n", x);
				Push(&S1, x);
			}
			ADVTOKEN();
		}
		Pop(&S1, &x);
		printf("Hasil=%d\n", x);
	}

	return 0;
}