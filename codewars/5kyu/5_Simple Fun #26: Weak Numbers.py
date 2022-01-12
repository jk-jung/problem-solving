def d(x): return len([i for i in range(x) if x % (i + 1) == 0])
r = [d(i + 1) for i in range(1000)]
w = [len([j for j in range(i) if r[j] > r[i]]) for i in range(1000)]

def weak_numbers(n):
    m = max(w[:n])
    return [m, len([x for x in range(n) if w[x] == m])]
