def penaltyShots(n, v):
    if n >= 5:
        if v[0] != v[1]: return 1
        return 2
    m = 5 - n
    r = 0

    if v[0] == v[1]:
        if m % 2 == 0: return m // 2 * 2 + 1
        return (m + 1) // 2 * 2
    if v[0] < v[1]:
        dif = v[1] - v[0]
        m += dif
        if m % 2 == 0: return max(0, m // 2 * 2 + 1 - dif * 2)
        return max(0, (m + 1) // 2 * 2 - dif * 2)
    dif = v[0] - v[1]
    m += dif

    k = m // 2 + 1
    if dif >= k: return 0
    return max(0, k * 2 - (m % 2 == 0) - dif * 2)
