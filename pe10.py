def sss(n):
    a=[1 for i in range(n)]
    a[0]=0
    a[1]=0
    a[2]=1
    pl=[]
    t=0
    s=0
    for i in range(2,n):
	if a[i]==1:
            pl.append(i)
            s+=i
            j=i*i
            t+=1
        while j<n:
            a[j]=0
            j+=i
    print(s)
sss(2000000)
