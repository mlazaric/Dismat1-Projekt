#!/bin/python
import math

n = int(int(input()) / 2) 
logn = math.ceil(math.log(n, 2))
sqrt3 = math.sqrt(3)
retval = (3 + sqrt3)/6
pot = 2 + sqrt3
eksp = 1

for i in range(1, logn + 2):
	if n & eksp:
		retval = retval * pot % 100000007

	pot = pot * pot % 100000007
	eksp = eksp * 2

print(math.ceil(retval))