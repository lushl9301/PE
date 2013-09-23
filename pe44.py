def main():
	min = 2147483647
	p = [n*(3*n-1)//2 for n in range(1, 3000)]
	length = len(p)
	for i in range(length):
		for j in range(i+1, length):
			if (p[i]+p[j]) in p and (p[j]-p[i]) in p:
				if (p[j]-p[i]<min):
					min = p[j] - p[i]
	print(min)
if __name__ == '__main__':
	main()
