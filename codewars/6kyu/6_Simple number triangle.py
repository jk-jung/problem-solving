r = [[], [1]]
for i in range(1, 500):
    t = [1]
    for j in range(1, i):
        t.append(r[-1][j] + t[-1])
    t.append(t[-1])
    r.append(t)

def solve(n):
    return sum(r[n])
