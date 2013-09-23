def calc(n):
	for i in range(1, n):
		if 10**i%n == 1:
			return i

for i in range(1001, 900, -1):
	if (i%5 != 0) and (i%2 != 0):
		print(i, ",", calc(i))
