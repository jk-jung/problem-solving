def proc_arrInt(v):
    def f(x):
        i = 1
        cnt = 0
        while i * i <= x:
            if x % i == 0:
                cnt += 1
                if x // i != i: cnt += 1
            i += 1
        return cnt

    v = [(f(x), x) for x in sorted(v)]
    p = max(v)[0]
    return [
        len(v),
        len([x for x in v if x[0] == 2]),
        [p, [x[1] for x in v if x[0] == p and p > 2]]
    ]
