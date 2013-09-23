sum = 0
fd = open('pe13.in', 'r')
for i in range(100):
	line = fd.readline()
	now = int(line)
	sum += now;
print(sum)
