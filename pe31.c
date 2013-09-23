#include <stdio.h>

int
main()
{
	int i, j, k;
	int coin[8] = {1,2,5,10,20,50,100,200};
	int f[210];
	for (i=0; i<210; i++)
		f[i] = 0;
	f[0] = 1;
	for (i=0; i<8;i++)
	{
		for (j=200; j>0; j--)
			for (k = j/coin[i]; k>0; k--)
				if (f[j-k*coin[i]])
					f[j] += f[j-k*coin[i]];
	}
	printf("%d\n", f[200]);

	return 0;
}