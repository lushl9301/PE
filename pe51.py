import sys
import datetime

def euler(n):
	a = [1 for i in range(n)]
	a[0], a[1], a[2] = 0, 0, 1
	pl = []
	t = s = 0
	for i in range(2,n):
		if a[i]:
			s+=i
			if i>100000:
				pl.append(i)
			j=i*i
			t+=1
			while j<n:
				a[j]=0
				j+=i
	return pl


def count_prime_num(prime_num, pos_list):

	prime_str = str(prime_num)
	length = len(pos_list)
	if (length == 2 and not (prime_str[pos_list[0]] == prime_str[pos_list[1]])) \
	or (length == 3 and not (prime_str[pos_list[0]] == prime_str[pos_list[1]] == prime_str[pos_list[2]])):
		return 0
	
	prime_list = list(prime_str)
	count = 0
	for i in range(10):
		for j in pos_list:
			prime_list[j] = str(i)
		if int("".join(prime_list)) in prime:
			count += 1
	if count == 8:
		print(prime_num, count)
		print(datetime.datetime.now() - t0)
		sys.exit()


def deepsearch(prime_num, length, pos_list, position):
	if length == 0:
		count_prime_num(prime_num, pos_list)
		return 0

	if position<5:
		position = position + 1
		deepsearch(prime_num, length, pos_list[:], position)
		position = position - 1
	
	if position<=5:
		pos_list.append(position)
		position = position + 1
		deepsearch(prime_num, length-1, pos_list[:], position)
		pos_list.pop()
		position = position - 1
	return 0

t0 = datetime.datetime.now()
prime = euler(1000000)
for j in prime:
	for i in [2, 3]:
		deepsearch(j, i, [], 0)
