def sumDig_nthTerm(x, v, n):
    a, b = divmod(n - 1 , len(v))
    r = x + sum(y * a + (y if i < b else 0) for i, y in enumerate(v))
    return sum(map(int, str(r)))
