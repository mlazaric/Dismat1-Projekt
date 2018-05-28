#! /bin/python
from functools import reduce
import operator

def prod(iterable):
    return reduce(operator.mul, iterable, 1)

def binomial(n, k):
	return prod(range(n, n - k, -1))/prod(range(1, k + 1))

def bernoulli(m):
	sum = 0

	for k in range(0, m + 1):
		for v in range(0, k + 1):
			sum += pow(-1, v) * binomial(k, v) * pow(v + 1, m)/(k + 1)

	return sum

n = int(input())

for i in range(0, n + 1):
	print(bernoulli(i) * binomial(n + 1, i) / (n + 1))