from __future__ import division
import sys

def printf(format, *args):
    sys.stdout.write(format % args)

for line in sys.stdin:
	line = line.strip()
	x = eval(line)
	printf("%.2f\n", x)

