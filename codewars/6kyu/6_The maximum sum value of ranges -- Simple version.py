def max_sum(v,r):
    return max(sum(v[i] for i in range(s, e + 1)) for s, e in r)