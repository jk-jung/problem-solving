def solve(v):
    a,b = 0, 0
    for i in range(1, len(v)):
        if v[i-1] < v[i]: a += 1
        else: b += 1
    if a == 0: return 'D'
    elif b == 0: return 'A'
    if a + b == 2: return 'RD' if v[0] < v[-1] else 'RA'
    return 'RD' if a == 1 else 'RA'
