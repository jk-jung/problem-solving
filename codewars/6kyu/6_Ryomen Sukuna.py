def sukuna(n):
    s = set()
    for i in range(2, int(n ** .5) + 1):
        k = 2
        while i ** k <= n:
            s.add(i ** k)
            k += 1
    return n - len(s)
