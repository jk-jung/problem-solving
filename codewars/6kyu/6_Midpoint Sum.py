def midpoint_sum(v):
    s, s1 = sum(v), 0
    for i in range(len(v)):
        if i and i != len(v) - 1 and s1 == s - v[i] - s1:
            return i
        s1 += v[i]
    return None
