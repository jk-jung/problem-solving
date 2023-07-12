def solve(a, b):
    if not a: return 1
    if not b: return 0
    r = solve(a, b[1:])
    if a[0] == b[0]: r += solve(a[1:], b[1:])
    return r
