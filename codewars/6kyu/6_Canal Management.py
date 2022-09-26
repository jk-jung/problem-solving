def canal_mania(aq, bq, k):
    r = 0
    def f(q):
        s, c = 0, 0
        for x in q:
            if s + x > k:
                s, c = 0, c + 1
            s += x
        if s: c += 1
        return c

    return max(f(aq), f(bq)) * 4 + sum(aq) * 2 + sum(bq) * 2