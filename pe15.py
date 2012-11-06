f = [[0 for i in range(21)] for j in range(21)]
f[0][0] = 1
for i in range(0, 21):
        f[i][0] = 1
        f[0][i] = 1
for i in range(1 , 21):
	for j in range(1 , 21):
		f[i][j] = f[i-1][j]+f[i][j-1]
for i in range(0, 20):
        print(f[i])
print(f[20][20])