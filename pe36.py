def convert2Binary(x):
	l = []
	while x>0:
		l.append(x%2)
		x //= 2
	return l

def main():
	sum = 0
	for i in range(1, 1000):
		s = str(i)
		l_x = list(s)
		l_x.reverse()
		s += "".join(l_x)
		x = int(s)
		l_x_bin = convert2Binary(x)
		l_x_bin_reverse = l_x_bin[:]
		l_x_bin_reverse.reverse()
		if l_x_bin[:] == l_x_bin_reverse[:]:
			sum += x;
			print(x)
	for i in range(1, 100):
		for j in range(10):
			s = str(i)
			l_x = list(s)
			l_x.reverse()
			s += str(j) + "".join(l_x)
			x = int(s)
			l_x_bin = convert2Binary(x)
			l_x_bin_reverse = l_x_bin[:]
			l_x_bin_reverse.reverse()
			if l_x_bin[:] == l_x_bin_reverse[:]:
				sum += x;
				print(x)
	for i in range(10):
		x = i
		l_x_bin = convert2Binary(x)
		l_x_bin_reverse = l_x_bin[:]
		l_x_bin_reverse.reverse()
		if l_x_bin[:] == l_x_bin_reverse[:]:
			sum += x;
			print(x)

	print(sum)

if __name__ == '__main__':
	main()
