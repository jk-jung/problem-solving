def josephus_survivor(n, k):
    k -= 1
    n = [i + 1 for i in range(n)]
    while len(n) > 1:
        x = k % len(n)
        n = n[x + 1:] + n[:x]
    return n[0]
