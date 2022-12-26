def distribution_of_candy(v):
    r, n = 0, len(v)
    while True:
        if len(set(v)) == 1: return [r, v[0]]
        v, r = [(v[i] + 1) // 2 + (v[(i - 1 + n) % n] + 1) // 2 for i in range(n)], r + 1
