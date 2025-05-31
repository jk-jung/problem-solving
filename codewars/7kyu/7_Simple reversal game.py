def solve(n,k):
    t = list(range(n))
    for i in range(n):
        t[i:] = t[i:][::-1]
    for i, x in enumerate(t):
        if x == k:
            return i