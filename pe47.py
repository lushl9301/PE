import math

def check(x):
	count = 0
	res = []
	if x%2 == 0:
		res.append(2)
		while x%2 ==0:
			x //= 2
	limit = math.sqrt(x+1)
	i = 3
	while i <= limit:
		if x % i == 0:
			res.append(i)
			x //= i
			limit = math.sqrt(x+i)
		else:
			i += 2
	if x != 1:
		res.append(x)
	return len(set(res))


def main():
	factors = [0]
	for i in range(1, 150000):
		factors.append(check(i))
	for i in range(1,149995):
		if (factors[i] == 4) and (factors[i+1] == 4) and (factors[i+2] == 4) and (factors[i+3] == 4):
			print(i)

if __name__ == '__main__':
	main()
