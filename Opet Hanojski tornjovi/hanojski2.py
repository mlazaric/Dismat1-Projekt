#! /bin/python

def graycode(n):
	if n == 1:
		return ['A', 'B', 'C']
	else:
		gc = graycode(n - 1)

		return ['A' + s for s in gc] + ['B' + s for s in reversed(gc)] + ['C' + s for s in gc]

n = int(input())
gray = graycode(n)

print(len(gray) - 1)

for str in gray:
	print(str)