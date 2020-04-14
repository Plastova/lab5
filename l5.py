from __future__ import print_function
import math

eps = 0.001
a=1
n=600


def func(x): 
	return math.sin(x)/((1+x)*math.sqrt(x))


def calc_A():
	return -10*math.log(eps/10)

def pryamoug_center(a,b,n):
	h = (A - a) / n
	res = 0
	for i in range(0,n):
		res += func(a + h * (i + 0.5))
	res *= h
	return res

def trapetsiy (a,b,n): 
	h = (A - a) / n
	res = 0
	for i in range(0,n-1):
		res += 0.5*(func(a + h*i) + func(a + h*(i+1)))
	res *= h
	return res

def runge (i1, i2):
	return abs((i1-i2)/2)
	

A = calc_A()
res=pryamoug_center (a,A,n)
res2=pryamoug_center (a,A,2*n)
print("1) Po formule pryamougolnikov s tsentralnoy tochkoy:\n\t\tI = ",res+eps)
res=runge (res, res2)
print("Pogreshnost po pravilu Runge: ",res)
res = trapetsiy(a,A,n)
res2 = trapetsiy(a,A,2*n)
print("\n2) Po formule trapetsiy:\n\t\tI = ",res+eps)
res=runge (res, res2)
print("Pogreshnost po pravilu Runge: ",res)


