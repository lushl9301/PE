def main():
	max = 0
	for i in range(193, 100000):
		num_set = list(str(i)+str(i*2))
		if '0' in num_set:
			continue
		if (len(num_set) == 9) and (len(set(num_set)) == 9):
		#make sure there are 9 digits in the list;
		#also, make sure there are 9 different digis.
			max = i
	print(max)


if __name__ == '__main__':
	main()
