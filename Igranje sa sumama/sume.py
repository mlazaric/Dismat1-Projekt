#! /bin/python
from sympy import N, bernoulli, binomial

n = int(input())

for i in range(0, n + 1):
	print(N(pow(-1, i) * bernoulli(i) * binomial(n + 1, i) / (n + 1)))