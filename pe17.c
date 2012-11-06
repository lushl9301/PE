#include<stdio.h>

//one to nineteen
int S[20] = {0,3,3,5,4,4,3,5,5,4,3,
				6,6,8,8,7,7,9,8,8};
//twenty thirdty ....
int D[10] = {0,0,6,6,5,5,5,7,6,6};
//hundred
int H = 7;
//thousand
int T = 8;
//and
int N = 3;


int main(){
	int i, a, b, c;
	int sum = 0;
	for (i=1; i<1000; i++){
		c = i%10;
		b = ((i%100) - c)/10;
		a = i/100;
		// greater than 100
		if (a != 0){
			sum +=S[a] + H;
			if (b != 0 || c != 0){
				sum += N;
			}
		}
		// [1 to 19]
		if (b == 0 || b == 1){
			sum += S[b*10 + c];
		} else{  //[20 to 99]
			sum += D[b] + S[c];
		}
	}

	//add one thousand
	sum += S[1] + T;
	printf("%d", sum);
}