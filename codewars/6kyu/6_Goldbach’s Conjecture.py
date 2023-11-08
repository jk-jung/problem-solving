def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))

def goldbach_partitions(n):
    if n % 2: return []
    r = []
    i = 1
    while i <= n - i:
        if p(i) and p(n - i):
            r.append(f'{i}+{n - i}')
        i += 1
    return r
