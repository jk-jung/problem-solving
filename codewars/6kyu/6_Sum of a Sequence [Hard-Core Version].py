def sequence_sum(s, e, t):
    dif = e - s
    if dif * t < 0: return 0
    n = abs(dif // t) + 1
    return n * (n - 1) // 2 * t + s * n
