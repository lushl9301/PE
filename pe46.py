def sss(n):
	a = [1 for i in range(n)]
	a[0], a[1], a[2] = 0, 0, 1
	pl = []
	t = s = 0
	for i in range(2,n):
		if a[i]:
			s+=i
			pl.append(i)
			j=i*i
			t+=1
			while j<n:
				a[j]=0
				j+=i
	return pl
def main():
	prime = sss(100000)
	twice_a_square = [2*i*i for i in range(1, 100)]
	for i in range(17, 100000):
		odd_composite = 2*i+1
		t = 0
		if not odd_composite in prime:
			for j in prime:
				if j>odd_composite:
					break
				x = odd_composite - j
				if x in twice_a_square:
					t = 1
					break
			if not t:
				print(odd_composite)
				return 0


if __name__ == '__main__':
	main()
