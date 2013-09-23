a = b = 1
t = 2
while True:
	b, a= a+b, b;
	t +=1
	if len(str(b))>=1000:
		print(t)
		break