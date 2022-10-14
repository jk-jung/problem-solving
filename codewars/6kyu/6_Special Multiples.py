c = [0 for i in range(10000)]
p = []
for i in range(2, 10000):
    if not c[i]:
        p.append(i)
        for j in range(i, 10000, i):
            c[j] = 1

def count_specMult(n, max_val):
    r = 1
    for i in range(n):r *= p[i]
    return max_val // r