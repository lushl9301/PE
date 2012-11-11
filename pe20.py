ans = 1
for i in range(1, 100):
	ans *= i
print(sum([int(i) for i in list(str(ans))]))