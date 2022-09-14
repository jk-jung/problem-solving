p = [0 for i in range(200000)]
s = ''
for i in range(2, 200000):
    if p[i] == 0:
        s += str(i)
        for j in range(i, 200000, i):
            p[j] = 1

def solve(a, b):
    return s[a:a + b]
