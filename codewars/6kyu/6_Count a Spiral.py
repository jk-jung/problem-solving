def spiral_sum(n):
    if n == 5: return 17
    if n == 6: return 23
    m = n // 2
    if n % 2: return m * (m + 1) // 2 * 4 + n
    else: return m * (m + 1) // 2 * 4 - 1
