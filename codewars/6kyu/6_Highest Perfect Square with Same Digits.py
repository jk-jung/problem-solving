from collections import defaultdict
c = defaultdict(list)
for i in range(4, 10000):
    s = ''.join(sorted(str(i * i)))
    if '0' not in s:
        c[s].append(i * i)
vv = []
for v in c.values():
    [vv.append((x, len(v), v[-1])) for x in v]
vv.sort()
def next_perfectsq_perm(x, k):
    for a, b, c in vv:
        if x < a and b == k:
            return c
