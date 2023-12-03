def min_distance(n):
    s = set()
    for i in range(1, int(n ** .5) + 1):
        if n % i == 0:
            s.add(i)
            s.add(n // i)
    s = sorted(s)
    return min(y - x for x, y in zip(s, s[1:]))
