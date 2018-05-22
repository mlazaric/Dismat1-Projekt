#! /bin/python
n = int(input())
out = 1

for k in range(n + 1, 2 * n + 1):
	out = out * k / 2

print(int(out % 100000007))