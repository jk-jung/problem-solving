def is_happy(n, pow):
    r = [n]
    while n:
        n = sum(map(lambda x: int(x) ** pow, str(n)))
        if n == 1: return [1]
        if n in r: return r[r.index(n):] + [n]
        r.append(n)
