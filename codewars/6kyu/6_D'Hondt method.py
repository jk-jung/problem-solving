def distribute_seats(n: int, v: tuple[int, ...])-> list[int]:
    r = [0 for _ in range(len(v))]
    c = [1 for _ in range(len(v))]
    for _ in range(n):
        m = 0
        for i in range(len(v)):
            if v[m] / c[m] < v[i] / c[i]:
                m = i
        r[m] += 1
        c[m] += 1
    return r
