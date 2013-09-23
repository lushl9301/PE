def is_palindrome(n):
	n = str(n)
	if n == n[::-1]:
		return 1
	return 0

def is_lychrel_num(n):
	for i in range(50):
		n_reverse = str(n)
		n += int(n_reverse[::-1])
		if is_palindrome(n):
			return 0
	return 1

def main():
	ans = 0
	for n in range(1, 10001):
		if is_lychrel_num(n):
			ans += 1
	print(ans)

if __name__ == '__main__':
	main()
