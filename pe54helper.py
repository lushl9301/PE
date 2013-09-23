st = file("poker.txt").readlines()
fp = file("data.txt", "w")
for i in st:
    fp.write(" " * 8 + '"' + i[0:len(i)-1] + '",\n')

    
