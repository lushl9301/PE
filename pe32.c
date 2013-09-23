#include <stdio.h>

int mul[10];
int
check()
{
	int i, j;
	for (i=0; i<4; i++)
		if (mul[i] == 0)
			return 0;
	for (i=0; i<4; i++)
		for (j=i+1; j<4; j++)
			if (mul[i] == mul[j])
				return 0;
	return 1;
}

int
main()
{
	int x1, x2, y, y_tmp, sum=0;
	int a, b, c, d, e;
	int *tmp;
	for (a=0; a<10; a++)
		mul[10] = 0;
	for ( a=1; a<10; a++)
		for ( b=1; b<10; b++)
			if (a!=b)
				for ( c=1; c<10; c++)
					if (c!=a && c!=b)
						for ( d=1; d<10; d++)
							if (d!=c && d!=a && d!=b)
								for ( e=1; e<10; e++)
									if (e!=d && e!=a && e!=b && e!=c)
									{
										x1 = a*10 + b;
										x2 = c*100 + d*10 + e;
										y = x1*x2;
										y_tmp = y;
										tmp = mul;
										while (y_tmp>0)
										{
											*tmp = y_tmp % 10;
											if (*tmp==a || *tmp==b || *tmp==c || *tmp==d || *tmp==e) 
											{
												y_tmp = -1;
												break;
											}
											y_tmp /= 10;
											tmp++;
										}
										if (y<9999 && y_tmp>=0 && check())
										{
											sum += y;
											printf("%d, %d, %d\n", x1, x2, y);
										}
										x1 = a;
										x2 = b*1000 + c*100 + d*10 + e;
										y = x1*x2;
										y_tmp = y;
										tmp = mul;
										while (y_tmp>0)
										{
											*tmp = y_tmp % 10;
											if (*tmp==a || *tmp==b || *tmp==c || *tmp==d || *tmp==e) 
											{
												y_tmp = -1;
												break;
											}
											y_tmp /= 10;
											tmp++;
										}
										if (y<9999 && y_tmp>=0 && check())
										{
											sum += y;
											printf("%d, %d, %d\n", x1, x2, y);
										}
									}
	printf("%d\n", sum);
	return 0;
}