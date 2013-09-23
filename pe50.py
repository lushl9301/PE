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
	prime = sss(1000000)
	length = len(prime)
	max_length = 0
	x = 0
	for i in range(10):
		l = 0
		total = 0
		seq = prime[i:]
		for j in seq:
			total += j
			l += 1
			if total > 1000000:
				break
			if total in prime and max_length < l:
				max_length = l
				x = total
				print(seq[:l])
	print(max_length)
	print(x)

if __name__ == '__main__':
	main()
