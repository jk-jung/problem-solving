s = """a	b	c	d	e	1	2	3
f	g	h	i	j	4	5	6
k	l	m	n	o	7	8	9
p	q	r	s	t	.	@	0
u	v	w	x	y	z	_	/
aA	 						"""
s = [x.split('\t') for x in s.split('\n')]
n, m = len(s), len(s[0])


def pos(x):
    for i in range(n):
        for j in range(m):
            if s[i][j] == x: return i, j

def tv_remote(words):
    y, x, st, r = 0, 0, False, 0
    for c in words:
        if c.isalpha() and c.isupper() != st:
            r += abs(y - 5) + x + 1
            y, x, st = 5, 0, not st
        c = c.lower()
        ny, nx = pos(c)
        r += abs(y - ny) + abs(x - nx) + 1
        y, x = ny, nx
    return r
