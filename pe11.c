#include <stdio.h>

int main()
{
    int a[20][20];
    FILE *fd = NULL;
    fd = fopen("pe11.in", "rw+");
    int i, j;
    int *p;
    for (i = 0; i<20;i++)
	for (p = a[i]; p<a[i]+20; p++)
	    fscanf(fd, "%d", p);
    int max, now;
    max = 0;
    for (i = 0; i<17; i++)
    {
	now = 1;
	for (j = 0; j<17; j++)
	{
	    now =a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
	    max = now>max ? now:max;
	}
    }
    for (i = 19; i>2; i--)
    {
	now = 1;
	for (j = 0; j<17; j++)
	{
	    now = a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
	    max = now>max ? now:max;
	}
    }
    fclose(fd);
    printf("%d", max);
    return 0;
}
