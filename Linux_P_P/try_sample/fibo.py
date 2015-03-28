def fibo(n):
	if n < 0:
		return -1
	if n in [0,1]:
		return 1
	a0 = 0;
	a1 = 1;
	an = 0;
	for i in range(2,n+1):
		an = a0+a1
		a0 = a1
		a1 = an
	return an

for i in range(1,50):
	print 'a',i,"=",fibo(i)