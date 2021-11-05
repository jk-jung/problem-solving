import numpy as np

mod = 12345787

m = 1 << 5
v = [[0 for _ in range(m)] for _ in range(m)]
for i in range(m):
    for j in range(m):
        need = i ^ (m - 1)
        if (need & j) != need: continue
        t = j ^ need
        def f(x): return t >> x & 1
        if f(0):
            if not f(1): continue
            t ^= 2
        if f(1):
            if not f(2): continue
            t ^= 4
        if f(2):
            if not f(3): continue
            t ^= 8
        if f(3):
            if not f(4): continue
            t ^= 16
        if f(4):
            continue
        v[i][j] += 1

s = [0 for _ in range(m)]
s[m-1] = 1
x = np.array(v)
r = np.array(v)
d = [0]
for i in range(1, 10001):
    r = r @ x % mod
    d.append((s @ r)[m-1])
    r = r @ x % mod

def five_by_2n(n):
    return d[n]
import numpy as np

mod = 12345787

m = 1 << 5
v = [[0 for _ in range(m)] for _ in range(m)]
for i in range(m):
    for j in range(m):
        need = i ^ (m - 1)
        if (need & j) != need: continue
        t = j ^ need
        def f(x): return t >> x & 1
        if f(0):
            if not f(1): continue
            t ^= 2
        if f(1):
            if not f(2): continue
            t ^= 4
        if f(2):
            if not f(3): continue
            t ^= 8
        if f(3):
            if not f(4): continue
            t ^= 16
        if f(4):
            continue
        v[i][j] += 1

s = [0 for _ in range(m)]
s[m-1] = 1
x = np.array(v)
r = np.array(v)
d = [0]
for i in range(1, 10001):
    r = r @ x % mod
    d.append((s @ r)[m-1])
    r = r @ x % mod

def five_by_2n(n):
    return d[n]
