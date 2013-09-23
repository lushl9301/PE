from itertools import *

def check(digits):
	prime = [2,3,5,7,11,13,17]
	length = 10
	l_prime = 6
	while length>3:
		tmp = int("".join(digits[length-3:length]))
		if tmp % prime[l_prime] != 0:
			return False
		length -= 1
		l_prime -= 1
	return True



def main():
	permutation_digit = list(permutations(str(i) for i in range(0,10)))
	#permutation_digit = [['1','4','0','6','3','5','7','2','8','9']]
	sum = 0
	for i in permutation_digit:
		if check(i):
			sum += int("".join(i))
	print(sum)


if __name__ == '__main__':
        main()
