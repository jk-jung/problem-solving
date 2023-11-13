def triangular_sum(n):
    for i in range(1, n):
        a = (i * (i + 1) // 2) ** 2 + ((i + 1) * (i + 2) // 2) ** 2
        if a == n: return True
        if a > n: return False
