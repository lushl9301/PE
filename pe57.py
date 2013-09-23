def main():
	numerator = 1
	denominator = 2
	ans = 0
	for i in range(1000):
		numerator += 2*denominator
		denominator, numerator = numerator, denominator
		if len(str(numerator+denominator))>len(str(denominator)):
			ans += 1
	print(ans)

if __name__ == '__main__':
	main()
