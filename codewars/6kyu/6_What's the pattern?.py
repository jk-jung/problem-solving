def find_pattern(v):
    v = [v[i] - v[i - 1] for i in range(1, len(v))]
    for i in range(1, len(v) + 1):
        if len(v) % i: continue
        if v == (v[:i] * len(v))[:len(v)]: return v[:i]
