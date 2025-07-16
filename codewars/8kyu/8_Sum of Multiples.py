def sum_mul(n, m):
    try:
        if m <= 0 or n <= 0:
            return 'INVALID'
        return sum(range(n, m, n))
    except:
        return 'INVALID'
