def shift(shift_prime):
	l = shift_prime[1:]
	l.append(shift_prime[0])
	return l

	
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
	count = 0
	prim, f = sss(1000000)
	for i in prim:
		shift_prime = list(str(i));
		t = 0
		for k in range(7):
			shift_prime = shift(shift_prime)
			new_prime = int("".join(shift_prime))
			if not f[new_prime]:
				t = 1
				break
		if not t:
			count += 1;
	print(count)	

if __name__ == '__main__':
	main()
