p = [0 for _ in range(100000)]
v = []
for i in range(2, 100000):
    if p[i]: continue
    v.append(i)
    for j in range(i + i, 100000, i): p[j] = 1

def num_primorial(n):
    r = 1
    for i in range(n):r *= v[i]
    return r