def solve(v):
    v = sorted(v)
    if v[0] + v[1] <= v[2]: return v[0] + v[1]
    t = v[0] + v[1] - v[2]
    return v[2] + min(v[0], t // 2)
