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

def check(a, b, c):
	list_a = list(str(a))
	list_b = list(str(b))
	list_c = list(str(c))
	if sorted(list_a) == sorted(list_b) == sorted(list_c):
		return 1
	return 0
	
def main():
	prime = sss(10000)
	_4bit_prime = []
	for i in prime:
		if i>1000:
			_4bit_prime.append(i)
	length = len(_4bit_prime)
	for i in range(0,length):
		for j in range(i+1, length):
			diff = _4bit_prime[j] - _4bit_prime[i]
			third_prime = _4bit_prime[j] + diff
			if third_prime in _4bit_prime:
				if check(_4bit_prime[i], _4bit_prime[j], third_prime):
					print(_4bit_prime[i], _4bit_prime[j], third_prime)
					#return 0


if __name__ == '__main__':
	main()
