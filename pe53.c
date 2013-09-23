#include <stdio.h>

int
main()
{
	int f[101][102];
	int i, j;
	
	for (i=0; i<101; i++)
	{
		f[i][0] = 1;
		f[i][i] = 1;
	}

	int count = 0;
	for (i=2; i<101; i++)
		for (j=1; j<i; j++)
		{
			f[i][j] = f[i-1][j-1] + f[i-1][j];
			if (f[i][j]>=1000000)
			{
				count++;
				f[i][j] = 1000000;
			}
		}

	printf("%d\n", count);
	
	return 0;
}