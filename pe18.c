#include <stdio.h>

int
main(){
	FILE *fp = NULL;
	fp = fopen("pe18.in", "rw+");
	int i, j, max;
	int a[15][15];
	for (i=0;i<15;i++)
		for (j=0;j<15;j++)
			a[i][j] = 0;

	for (i=0; i<15; i++){
		for (j=0; j<=i; j++){
			fscanf(fp, "%d", &a[i][j]);
		}
	}
	for (i=14; i>0; i--){
		for (j=0; j<i; j++){
			max = a[i][j]>a[i][j+1] ? a[i][j] : a[i][j+1];
			a[i-1][j] += max;
		}
	}
	for (i=0;i<15;i++){
		for (j=0; j<=i;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("%d", a[0][0]);
	fclose(fp);
}