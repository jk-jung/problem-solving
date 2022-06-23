def solve(v):
    return sorted(v, key=lambda x: (-v.count(x), x))
