sum_up = 25
last_max = 9	#last_max is the previous circle's largest one. on the up-right corner.
base = 25 		#base is the base difference between last_max and the new circle's min.
for circle in range(2, 501):
	base += 2
	sum_up += base*10 + last_max*4
	last_max += base*4
print(sum_up)