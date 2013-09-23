def main():
	maximun = xa = xb = 0
	for a in range(1, 100):
		for b in range(1, 100):
			sum_up = sum(int(i) for i in list(str(a**b)))
			if sum_up>maximun:
				maximun = sum_up
				xa = a
				xb = b
	print(maximun, xa, xb)

if __name__ == '__main__':
	main()
