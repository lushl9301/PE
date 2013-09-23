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

def isprime(n, prime_list):
	if n in prime_list:
		return True
	for i in prime_list:
		if n<i:
			return True
		if n%i == 0:
			return False
	return True

def dfs(left, prime_list, k, choice):


def main():
	dfs(5, pl, 0, [])