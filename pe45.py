import math

def is_triangle(n):
	x = int((math.sqrt(8*n+1)-1)//2)
	if x*(x+1)//2 == n:
		return 1
	return 0
def is_pentagonal(n):
	x = int((math.sqrt(24*n+1)+1)//6)
	if x*(3*x-1)//2 == n:
		return 1
	return 0


def main():
	for i in range(144, 100000):
		hexagonal = i*(2*i-1)
		if is_triangle(hexagonal) and is_pentagonal(hexagonal):
			print(hexagonal)
			break
if __name__ == '__main__':
	main()
