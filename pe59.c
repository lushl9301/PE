#include <stdio.h>

int
main()
{
	FILE *fp = NULL;
	fp = fopen("cipher1.txt","r");
	int a[100];
	int i, x;
	for (i=0; i<100; i++)
		a[i] = 0;
	//int ans = 0, now=0;
	//char key[3];
	//key[0] = 'g'; key[1] = 'o'; key[2] = 'd';
	while (fscanf(fp, "%d", &x)!=EOF)
	{
		a[x]++;
	//	ans += x^(int)key[now];
	//	now = (now+1) % 3;
	}
	//printf("%d\n", ans);
	fclose(fp);
	int count, max;
	for (count=0; count<10; count++)
	{
		max = 0;
		x = 0;
		for (i=0; i<100; i++)
			if (a[i]>max)
			{
				max = a[i];
				x = i;
			}
		printf("%d %d %d\n", x, 101^x, max);
		a[x] = -1;
	}

	return 0;
}