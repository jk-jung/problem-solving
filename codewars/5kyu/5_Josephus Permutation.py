def josephus(n, k):
    k -= 1
    r = []
    while len(n):
        x = k % len(n)
        r.append(n[x])
        n = n[x + 1:] + n[:x]
    return r
