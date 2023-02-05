def find_spec_partition(n, k, com):
    if com == 'min': return [n - k + 1] + [1] * (k - 1)
    r = []
    for i in range(k):
        r.append(n // (k - i))
        n -= r[-1]
    return r[::-1]
