def absolute_values_sum_minimization(v):
    t = min(sum(abs(x - y) for y in v) for x in sorted(v))
    for x in sorted(v):
        if sum(abs(x - y) for y in v) == t: return x
