def order_breaker(v):
    for i in range(len(v)):
        t = v[:i] + v[i + 1:]
        if sorted(t) == t:
            return v[i]
