#!/usr/bin/python
import random
import sys
n=4;
if (len(sys.argv) > 1):
	n=int(sys.argv[1])
for i in range(n):
	for j in range(n):
		print random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ") + " ",
	print
