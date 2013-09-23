def check(n):
	set1 = set(list(str(n)))
	tmp = n
	for i in range(0, 5):
		tmp += n
		new_set = set(list(str(tmp)))
		if new_set != set1:
			return 0
	return 1

def main():
	for i in range(1, 1000000):
		if check(i):
			print(i)
			return 0

if __name__ == '__main__':
	main()
