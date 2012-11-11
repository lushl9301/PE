#include <stdio.h>
#include <stdlib.h>
 
unsigned int sum_divisors(unsigned int n) {
    unsigned int s = 0, i = 1;
    while(i < n) {
        if(n % i == 0) s = s + i;
        i++;
    }
    return s;
}
 
unsigned int sum_amicable_pairs(unsigned int low, unsigned int high) {
    unsigned int a = low, b, sum = 0;
    while(a <= high) {
        b = sum_divisors(a);
        if(b > a && sum_divisors(b) == a) sum = sum + a + b;
        a++;
    }
    return sum;
}
 
int main(int argc, char **argv) {
    unsigned int ans = sum_amicable_pairs(1,10000);
    printf("result: %d\n",ans);
    return 0;
}