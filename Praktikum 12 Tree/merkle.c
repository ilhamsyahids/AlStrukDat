// ILHAM SYAHID S
// 13518028

#include <stdio.h>
#include "bintree.h"

BinTree rek(int h)
{
	if (h == 0)
	{
		int num;
		scanf("%d", &num);
		return AlokNode(num);
	}
	BinTree root = AlokNode(0);
	Left(root) = rek(h - 1);
	Right(root) = rek(h - 1);
	Akar(root) = Info(Left(root)) + Info(Right(root));
	return root;
}

int main()
{
	int N;
	scanf("%d", &N);
	long long i = 1;
	int count = 0;
	while (i < N)
	{
		i = i << 1;
		count++;
	}
	if (i > N)
		printf("Jumlah masukan tidak sesuai\n");
	else
	{
		BinTree T = rek(count);
		PrintTree(T, 2);
	}
	return 0;
}