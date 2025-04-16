def three_powers(n):
    r = []
    for i in range(1000):
        if n >> i & 1:r.append(i + 1)
    if len(r) > 3: return False
    return sum(r) >= 3
