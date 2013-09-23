#include <stdio.h>
int f[1000];

int
init()
{
	int i;
	for (i=0; i<1000; i++)
		f[i] = 0;
}

int
main()
{
	int a, b;
	int l, sum, i, carry;
	int max=0, xa=0, xb=0;
	for (a=1; a<100; a++)
	{
		l = 1;
		init();
		f[0] = a;
		while (f[l]>9)
		{
			f[l] = f[l-1]/10;
			f[l-1] %= 10;
			l++;
		}
		for (b=1; b<99; b++)
		{
			sum = 0;
			carry = 0;
			for (i=0; i<l; i++)
			{
				f[i] = f[i]*a + carry;
				carry = f[i]/10;
				f[i] %= 10;
				sum += f[i];
			}
			while (carry>0)
			{
				f[l] += carry;
				carry = f[l]/10;
				f[l] %= 10;
				sum += f[l++];
			}

			if (sum>max)
			{
				max = sum;
				xa = a;
				xb = b;
			}
			
			//printf("%d %d\n", a, b);
			//for (i=l-1; i>=0; i--)
			//{
			//	printf("%d", f[i]);
			//}
			//printf("\n");
		}
	}

	printf("%d %d %d\n", max, xa, xb+1);

	return 0;
}