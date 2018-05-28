#! /bin/python
n = int(input())
out = 1

for k in range(n + 1, 2 * n + 1):
	out = (out * k / 2) % 100000007

print(int(out))