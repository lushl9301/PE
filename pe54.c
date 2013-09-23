#include <stdio.h>

int 

int
init()
{
	int i;
	for (i=0; i<5; i++)
	{
		fscanf(fp, "%s", play1[i]);
	}
	for (i=0; i<5; i++)
	{
		fscanf(fp, "%s", play2[i]);
	}
	if (compare(play1, play2))
		ans++;
}

int
main()
{
	int ans = 0;
	FILE *fp = NULL;
	fp = fopen("pokerTest.txt", "r");
	char play1[5][2], play2[5][2];
	int n;
	for (n=0; n<1000; n++)
	{
		init;
	}
	return 0;
}