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
	return pl, a

def main():
	prime, f = sss(1000000)
	#print(prime)
	sum = 0
	for i in prime:
		x = i;
		t = 1
		while x>0:
			if not f[x]:
				t = 0
				break
			x //= 10
			
		if t:
			x = i
			length = len(str(x))
			while length>=0:
				if not f[x]:
					t = 0
					break
				x %= 10**length
				length -= 1
		if t:
			print(i)
			sum += i
	
	print(sum)

if __name__ == '__main__':
	main()
