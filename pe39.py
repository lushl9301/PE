import math

def main():
	f = [0 for i in range(1001)]
	for i in range(1, 1000):
		c = i*i
		for a in range(1, i):
			b = c - a*a
			if b<0:
				break
			sqrt_b = math.ceil(math.sqrt(b))
			if i+a+sqrt_b>1000:
				break
			if b == sqrt_b**2:
				f[i+a+sqrt_b] += 1
	max = 0
	x = 0
	for i in range(1001):
		if f[i]>=max:
			max = f[i]
			x = i
	print(max, x)



if __name__ == '__main__':
	main()
