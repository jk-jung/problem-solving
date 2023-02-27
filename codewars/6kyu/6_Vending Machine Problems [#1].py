def optimal_number_of_coins(n, v):
    d = [1 << 30 for _ in range(n + 1)]
    d[0] = 0
    for x in v:
        for i in range(x, n + 1):
            d[i] = min(d[i], d[i-x] + 1)
    return d[n]
